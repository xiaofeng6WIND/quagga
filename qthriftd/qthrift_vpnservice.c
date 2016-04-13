/* qthrift core structures and API
 * Copyright (c) 2016 6WIND,
 *
 * This file is part of GNU Quagga.
 *
 * GNU Quagga is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * GNU Quagga is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Quagga; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */
#include <zebra.h>

#include "thread.h"
#include "memory.h"
#include "hash.h"
#include "log.h"
#include "linklist.h"
#include "command.h"

#include "qthriftd/qthrift_memory.h"
#include "qthriftd/qthrift_thrift_wrapper.h"
#include "qthriftd/bgp_configurator.h"
#include "qthriftd/bgp_updater.h"
#include "qthriftd/qthrift_bgp_configurator.h"
#include "qthriftd/qthrift_bgp_updater.h"
#include "qthriftd/qthrift_vpnservice.h"
#include "qthriftd/qthrift_bgp_configurator.h"
#include "qthriftd/qthriftd.h"

void qthrift_vpnservice_setup(struct qthrift_vpnservice *setup)
{
  setup->qthrift_listen_port = QTHRIFT_LISTEN_PORT;
  setup->qthrift_notification_port = QTHRIFT_NOTIFICATION_PORT;
}

void qthrift_vpnservice_terminate(struct qthrift_vpnservice *setup)
{
  setup->qthrift_listen_port = 0;
  setup->qthrift_notification_port = 0;
}

void qthrift_vpnservice_terminate_thrift_bgp_updater_client (struct qthrift_vpnservice *setup)
{
  if(!setup)
    return;
  if(setup->bgp_updater_client)
    g_object_unref(setup->bgp_updater_client);
  setup->bgp_updater_client = NULL;
  if(setup->bgp_updater_protocol)
    g_object_unref(setup->bgp_updater_protocol);
  setup->bgp_updater_protocol = NULL;
  if(setup->bgp_updater_transport)
    g_object_unref(setup->bgp_updater_transport);
  setup->bgp_updater_transport = NULL;
  if(setup->bgp_updater_socket)
    g_object_unref(setup->bgp_updater_socket);
  setup->bgp_updater_socket = NULL;
}

gboolean qthrift_vpnservice_setup_thrift_bgp_updater_client (struct qthrift_vpnservice *setup)
{
  GError *error = NULL;
  gboolean response;

  if(!setup->bgp_updater_socket)
    setup->bgp_updater_socket =
      g_object_new (THRIFT_TYPE_SOCKET,
                    "hostname",  tm->qthrift_notification_address,
                    "port",      setup->qthrift_notification_port,
                    NULL);
  if(!setup->bgp_updater_transport)
    setup->bgp_updater_transport =
      g_object_new (THRIFT_TYPE_BUFFERED_TRANSPORT,
                    "transport", setup->bgp_updater_socket,
                    NULL);
  if(!setup->bgp_updater_protocol)
    setup->bgp_updater_protocol  =
      g_object_new (THRIFT_TYPE_BINARY_PROTOCOL,
                    "transport", setup->bgp_updater_transport,
                    NULL);
  /* In the C (GLib) implementation of Thrift, service methods on the
     server are accessed via a generated client class that implements
     the service interface. In this tutorial, we access a Calculator
     service through an instance of CalculatorClient, which implements
     CalculatorIf. */
  if(!setup->bgp_updater_client)
    setup->bgp_updater_client = 
      g_object_new (TYPE_BGP_UPDATER_CLIENT,
                    "input_protocol",  setup->bgp_updater_protocol,
                    "output_protocol", setup->bgp_updater_protocol,
                    NULL);
  response = thrift_transport_open (setup->bgp_updater_transport, &error);
  return response;
}

void qthrift_vpnservice_setup_thrift_bgp_configurator_server (struct qthrift_vpnservice *setup)
{
  /* Create our server socket, which binds to the specified port and
     listens for client connections */
  setup->bgp_configurator_server_transport =
    g_object_new (THRIFT_TYPE_SERVER_SOCKET,
                  "port", setup->qthrift_listen_port,
                  NULL);
  /* Create an instance of our handler, which provides the service's
     methods' implementation */
  setup->bgp_configurator_handler =
      g_object_new (TYPE_INSTANCE_BGP_CONFIGURATOR_HANDLER, NULL);

  /* Create an instance of the service's processor, automatically
     generated by the Thrift compiler, which parses incoming messages
     and dispatches them to the appropriate method in the handler */
  setup->bgp_configurator_processor = g_object_new (TYPE_BGP_CONFIGURATOR_PROCESSOR,
                                  "handler", setup->bgp_configurator_handler,
                                  NULL);
}

void qthrift_vpnservice_terminate_thrift_bgp_configurator_server (struct qthrift_vpnservice *setup)
{
  if(!setup)
    return;
  g_object_unref(setup->bgp_configurator_handler);
  setup->bgp_configurator_handler = NULL;
  g_object_unref(setup->bgp_configurator_processor);
  setup->bgp_configurator_processor = NULL;
  g_object_unref(setup->bgp_configurator_server_transport);
  setup->bgp_configurator_server_transport = NULL;
}

void qthrift_vpnservice_get_context (struct qthrift_vpnservice **setup)
{
  if(!tm->qthrift)
    *setup = NULL;
  *setup = tm->qthrift->qthrift_vpnservice;
}

u_int16_t qthrift_vpnservice_get_thrift_bgp_configurator_server_port (struct qthrift_vpnservice *setup)
{
  return setup->qthrift_listen_port;
}

void qthrift_vpnservice_set_thrift_bgp_configurator_server_port (struct qthrift_vpnservice *setup, \
                                                                 u_int16_t thrift_listen_port)
{
  setup->qthrift_listen_port = thrift_listen_port;
}

u_int16_t qthrift_vpnservice_get_thrift_bgp_updater_client_port (struct qthrift_vpnservice *setup)
{
  return setup->qthrift_notification_port;
}

void qthrift_vpnservice_set_thrift_bgp_updater_client_port (struct qthrift_vpnservice *setup, uint16_t thrift_notif_port)
{
  setup->qthrift_notification_port = thrift_notif_port;
}

void qthrift_vpnservice_terminate_client(struct qthrift_vpnservice_client *peer)
{
  if(peer == NULL)
    return;
  /* peer destroy */
  thrift_transport_close(peer->transport, NULL);
  g_object_unref(peer->transport_buffered);
  g_object_unref(peer->protocol);
  peer->protocol = NULL;
  g_object_unref(peer->simple_server);
  peer->simple_server = NULL;
  peer->server = NULL;
}

void qthrift_vpnservice_setup_client(struct qthrift_vpnservice_client *peer,
                                     struct qthrift_vpnservice *server, \
                                     ThriftTransport *transport)
{
  if(!peer)
    return;
  peer->transport = transport;
  peer->transport_buffered =
    g_object_new (THRIFT_TYPE_BUFFERED_TRANSPORT,
                  "transport", transport,
                  NULL);
  peer->protocol =
    g_object_new (THRIFT_TYPE_BINARY_PROTOCOL,
                  "transport", peer->transport_buffered,
                  NULL);
  /* Create the server itself */
  peer->simple_server =
    g_object_new (THRIFT_TYPE_SIMPLE_SERVER,
                  "processor",  server->bgp_configurator_processor,
                  NULL);
  if(peer->simple_server && &(peer->simple_server->parent))
    peer->server = &(peer->simple_server->parent);
  return;
}
