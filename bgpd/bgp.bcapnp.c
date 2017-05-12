/*
 * AUTOGENERATED FILE - DO NOT EDIT
 * derived from GPLv2+ sources
 */
#include <stdbool.h>
#include "c-capnproto/capn.h"
#include "bgp.bcapnp.h"

static const capn_text capn_val0 = {0, ""};


#include "zebra.h"
#include "bgpd.h"

afi_t qcapn_AfiSafiKey_get_afi(capn_ptr p)
{
    capn_resolve(&p);
    return capn_read8(p, 0);
}


safi_t qcapn_AfiSafiKey_get_safi(capn_ptr p)
{
    capn_resolve(&p);
    return capn_read8(p, 1);
}


afi_t qcapn_AfiKey_get_afi(capn_ptr p)
{
    capn_resolve(&p);
    return capn_read8(p, 0);
}

void qcapn_VRFTableIter_set(struct prefix *s, capn_ptr p)
{
    capn_resolve(&p);
    {
      /* MISSING: prefix */
    }
}

void qcapn_BGP_set(struct bgp *s, capn_ptr p)
{
    capn_resolve(&p);
    {
      /* MISSING: as */
    }
    {
      /* MISSING: name */
    }
    {
      struct in_addr router_id_static;
      
    {
        capn_ptr tmp_p = capn_getp(p, 1, 1);
        router_id_static.s_addr = htonl(capn_read32(tmp_p, 0));
    }
      bgp_router_id_static_set(s, router_id_static);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 0));
      if (flags) bgp_flag_set(s, BGP_FLAG_ALWAYS_COMPARE_MED);
	else bgp_flag_unset(s, BGP_FLAG_ALWAYS_COMPARE_MED);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 1));
      if (flags) bgp_flag_set(s, BGP_FLAG_DETERMINISTIC_MED);
	else bgp_flag_unset(s, BGP_FLAG_DETERMINISTIC_MED);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 2));
      if (flags) bgp_flag_set(s, BGP_FLAG_MED_MISSING_AS_WORST);
	else bgp_flag_unset(s, BGP_FLAG_MED_MISSING_AS_WORST);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 3));
      if (flags) bgp_flag_set(s, BGP_FLAG_MED_CONFED);
	else bgp_flag_unset(s, BGP_FLAG_MED_CONFED);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 4));
      if (flags) bgp_flag_set(s, BGP_FLAG_NO_DEFAULT_IPV4);
	else bgp_flag_unset(s, BGP_FLAG_NO_DEFAULT_IPV4);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 5));
      if (flags) bgp_flag_set(s, BGP_FLAG_NO_CLIENT_TO_CLIENT);
	else bgp_flag_unset(s, BGP_FLAG_NO_CLIENT_TO_CLIENT);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 6));
      if (flags) bgp_flag_set(s, BGP_FLAG_ENFORCE_FIRST_AS);
	else bgp_flag_unset(s, BGP_FLAG_ENFORCE_FIRST_AS);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 4) & (1 << 7));
      if (flags) bgp_flag_set(s, BGP_FLAG_COMPARE_ROUTER_ID);
	else bgp_flag_unset(s, BGP_FLAG_COMPARE_ROUTER_ID);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 0));
      if (flags) bgp_flag_set(s, BGP_FLAG_ASPATH_IGNORE);
	else bgp_flag_unset(s, BGP_FLAG_ASPATH_IGNORE);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 1));
      if (flags) bgp_flag_set(s, BGP_FLAG_IMPORT_CHECK);
	else bgp_flag_unset(s, BGP_FLAG_IMPORT_CHECK);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 2));
      if (flags) bgp_flag_set(s, BGP_FLAG_NO_FAST_EXT_FAILOVER);
	else bgp_flag_unset(s, BGP_FLAG_NO_FAST_EXT_FAILOVER);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 3));
      if (flags) bgp_flag_set(s, BGP_FLAG_LOG_NEIGHBOR_CHANGES);
	else bgp_flag_unset(s, BGP_FLAG_LOG_NEIGHBOR_CHANGES);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 4));
      if (flags) bgp_flag_set(s, BGP_FLAG_GRACEFUL_RESTART);
	else bgp_flag_unset(s, BGP_FLAG_GRACEFUL_RESTART);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 5));
      if (flags) bgp_flag_set(s, BGP_FLAG_ASPATH_CONFED);
	else bgp_flag_unset(s, BGP_FLAG_ASPATH_CONFED);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 6));
      if (flags) bgp_flag_set(s, BGP_FLAG_ASPATH_MULTIPATH_RELAX);
	else bgp_flag_unset(s, BGP_FLAG_ASPATH_MULTIPATH_RELAX);
      
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 5) & (1 << 7));
      if (flags) bgp_flag_set(s, BGP_FLAG_GR_PRESERVE_FWD);
	else bgp_flag_unset(s, BGP_FLAG_GR_PRESERVE_FWD);
    }
    {
      u_int32_t default_local_pref;
      default_local_pref = capn_read32(p, 12);
      if (default_local_pref) { bgp_default_local_preference_set(s, default_local_pref); } else { bgp_default_local_preference_unset(s); }
      
    }
    {
      u_int32_t keepalive;
      u_int32_t holdtime;
      keepalive = capn_read32(p, 20);
      holdtime = capn_read32(p, 16);
      if (keepalive || holdtime) { bgp_timers_set(s, keepalive, holdtime); } else { bgp_timers_unset(s); }
      
      
    }
    {
      s->restart_time = capn_read32(p, 24);
    }
    {
      const char * notify_zmq_url;
      { capn_text tp = capn_get_text(p, 2, capn_val0); notify_zmq_url = tp.str; }
      bgp_notify_zmq_url_set(s, notify_zmq_url);
      
    }
    {
      const char * logFile, *logLevel;
      { capn_text tp = capn_get_text(p, 3, capn_val0); logFile = tp.str; }
      { capn_text tp = capn_get_text(p, 4, capn_val0); logLevel = tp.str; }
      if (strlen(logFile) > 0 && strlen(logLevel) > 0) {
          set_log_file_with_level(logFile, logLevel);
      }
    }
    s->distance_ebgp = capn_read8(p, 6);
    s->distance_ibgp = capn_read8(p, 7);
    s->distance_local = capn_read8(p, 8);
    s->stalepath_time = capn_read32(p, 28);
    s->restart_time = capn_read32(p, 24);
}


as_t qcapn_BGP_get_as(capn_ptr p)
{
    capn_resolve(&p);
    return capn_read32(p, 0);
}

void qcapn_BGPAfiSafi_set(struct bgp *s, capn_ptr p, afi_t afi, safi_t safi)
{
    capn_resolve(&p);
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 0) & (1 << 0));
      if (flags) bgp_af_flag_set(s, BGP_CONFIG_DAMPENING, afi, safi);
        else bgp_af_flag_unset(s, BGP_CONFIG_DAMPENING, afi, safi);
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 0) & (1 << 1));
      if (flags)
      {
        bgp_af_flag_set(s, BGP_CONFIG_ASPATH_MULTIPATH_RELAX, afi, safi);
      }
      else
      {
        bgp_af_flag_unset(s, BGP_CONFIG_ASPATH_MULTIPATH_RELAX, afi, safi);
      }
    }
    {
      u_int16_t flags;
      flags = !!(capn_read8(p, 0) & (1 << 2));
      if (flags)
      {
        uint8_t max = capn_read8(p, 3);
        bgp_af_flag_set(s, BGP_CONFIG_MULTIPATH, afi, safi);
        bgp_maximum_paths_set (s, afi, safi,
                               BGP_PEER_EBGP, max);
        bgp_maximum_paths_set (s, afi, safi,
                               BGP_PEER_IBGP, max);
        bgp_maximum_paths_set (s, AFI_IP, SAFI_UNICAST,
                               BGP_PEER_EBGP, max);
        bgp_maximum_paths_set (s, AFI_IP, SAFI_UNICAST,
                               BGP_PEER_IBGP, max);
        bgp_vrfs_maximum_paths_set(s, afi, safi, max);
      }
      else
      {
        bgp_af_flag_unset(s, BGP_CONFIG_MULTIPATH, afi, safi);
        bgp_maximum_paths_unset (s, afi, safi,
                                 BGP_PEER_EBGP);
        bgp_maximum_paths_unset (s, afi, safi,
                                 BGP_PEER_IBGP);
        bgp_maximum_paths_unset (s, AFI_IP, SAFI_UNICAST,
                                 BGP_PEER_EBGP);
        bgp_maximum_paths_unset (s, AFI_IP, SAFI_UNICAST,
                                 BGP_PEER_IBGP);
        bgp_vrfs_maximum_paths_set(s, afi, safi, 1);
      }
    }
}

void qcapn_BGPPeer_set(struct peer *s, capn_ptr p)
{
    capn_resolve(&p);
    {
      /* MISSING: as */
    }
    {
      /* MISSING: host */
    }
    {
      const char * desc;
      { capn_text tp = capn_get_text(p, 1, capn_val0); desc = tp.str; }
      if (desc) { peer_description_set(s, desc); } else { peer_description_unset(s); }
      
    }
    {
      unsigned port;
      port = capn_read16(p, 4);
      if (port) { peer_port_set(s, port); } else { peer_port_unset(s); }
      
    }
    {
      u_int32_t weight;
      weight = capn_read32(p, 8);
      if (weight) { peer_weight_set(s, weight); } else { peer_weight_unset(s); }
      
    }
    {
      u_int32_t keepalive;
      u_int32_t holdtime;
      keepalive = capn_read32(p, 16);
      holdtime = capn_read32(p, 12);
      if (keepalive || holdtime) { peer_timers_set(s, keepalive, holdtime); } else { peer_timers_unset(s); }
      
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 0));
      if (flags) peer_flag_set(s, PEER_FLAG_PASSIVE);
	else peer_flag_unset(s, PEER_FLAG_PASSIVE);
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 1));
      if (flags) peer_flag_set(s, PEER_FLAG_SHUTDOWN);
	else peer_flag_unset(s, PEER_FLAG_SHUTDOWN);
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 2));
      if (flags) peer_flag_set(s, PEER_FLAG_DONT_CAPABILITY);
	else peer_flag_unset(s, PEER_FLAG_DONT_CAPABILITY);
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 3));
      if (flags) peer_flag_set(s, PEER_FLAG_OVERRIDE_CAPABILITY);
	else peer_flag_unset(s, PEER_FLAG_OVERRIDE_CAPABILITY);
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 4));
      if (flags) peer_flag_set(s, PEER_FLAG_STRICT_CAP_MATCH);
	else peer_flag_unset(s, PEER_FLAG_STRICT_CAP_MATCH);
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 5));
      if (flags) peer_flag_set(s, PEER_FLAG_DYNAMIC_CAPABILITY);
	else peer_flag_unset(s, PEER_FLAG_DYNAMIC_CAPABILITY);
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 6));
      if (flags) peer_flag_set(s, PEER_FLAG_DISABLE_CONNECTED_CHECK);
	else peer_flag_unset(s, PEER_FLAG_DISABLE_CONNECTED_CHECK);
      
    }
    {
      u_int32_t flags;
      flags = !!(capn_read8(p, 6) & (1 << 7));
      if (flags)
        peer_connect_with_update_source_only_set (s, 1);
      else 
        peer_connect_with_update_source_only_set (s, 0);
    }
    {
      int ttl;
      ttl = capn_read32(p, 20);
      if (ttl) { peer_ebgp_multihop_set(s, ttl); } else { peer_ebgp_multihop_unset(s); }
      
    }
    {
      char * update_source = NULL;
      int len;
      capn_text tp = capn_get_text(p, 2, capn_val0);
      update_source = (char *)tp.str;
      len = tp.len;
      if (update_source && len != 0)
        {
          union sockunion su;
	  int ret = str2sockunion (update_source, &su);
	  if (ret == 0)
            peer_update_source_addr_set (s, &su);
        }
      else
        {
	  peer_update_source_unset (s);
        }
    }
}


as_t qcapn_BGPPeer_get_as(capn_ptr p)
{
    capn_resolve(&p);
    return capn_read32(p, 0);
}


const char * qcapn_BGPPeer_get_host(capn_ptr p)
{
    capn_resolve(&p);
    capn_text tp = capn_get_text(p, 0, capn_val0);; return tp.str;
}

void qcapn_BGPPeerAfiSafi_set(struct peer *s, capn_ptr p, afi_t afi, safi_t safi)
{
    capn_resolve(&p);
    {
      u_char afc;
      afc = !!(capn_read8(p, 0) & (1 << 0));
      peer_afc_set(s, afi, safi, afc);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 0) & (1 << 1));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_SEND_COMMUNITY);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_SEND_COMMUNITY);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 0) & (1 << 2));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_SEND_EXT_COMMUNITY);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_SEND_EXT_COMMUNITY);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 0) & (1 << 3));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_NEXTHOP_SELF);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_NEXTHOP_SELF);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 0) & (1 << 4));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_REFLECTOR_CLIENT);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_REFLECTOR_CLIENT);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 0) & (1 << 5));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_RSERVER_CLIENT);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_RSERVER_CLIENT);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 0) & (1 << 6));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_SOFT_RECONFIG);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_SOFT_RECONFIG);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 0) & (1 << 7));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_AS_PATH_UNCHANGED);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_AS_PATH_UNCHANGED);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 0));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_NEXTHOP_UNCHANGED);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_NEXTHOP_UNCHANGED);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 1));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_MED_UNCHANGED);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_MED_UNCHANGED);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 2));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_DEFAULT_ORIGINATE);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_DEFAULT_ORIGINATE);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 3));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_REMOVE_PRIVATE_AS);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_REMOVE_PRIVATE_AS);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 4));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_ALLOWAS_IN);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_ALLOWAS_IN);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 5));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_ORF_PREFIX_SM);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_ORF_PREFIX_SM);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 6));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_ORF_PREFIX_RM);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_ORF_PREFIX_RM);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 1) & (1 << 7));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_MAX_PREFIX);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_MAX_PREFIX);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 2) & (1 << 0));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_MAX_PREFIX_WARNING);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_MAX_PREFIX_WARNING);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 2) & (1 << 1));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_NEXTHOP_LOCAL_UNCHANGED);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_NEXTHOP_LOCAL_UNCHANGED);
      
    }
    {
      u_int32_t af_flags;
      af_flags = !!(capn_read8(p, 2) & (1 << 2));
      if (af_flags) peer_af_flag_set(s, afi, safi, PEER_FLAG_NEXTHOP_SELF_ALL);
	else peer_af_flag_unset(s, afi, safi, PEER_FLAG_NEXTHOP_SELF_ALL);
      
    }
    {
      char allowas_in;
      allowas_in = capn_read8(p, 3);
      if (allowas_in) { peer_allowas_in_set(s, afi, safi, allowas_in); } else { peer_allowas_in_unset(s, afi, safi); }
      
    }
}

void qcapn_BGPVRF_set(struct bgp_vrf *s, capn_ptr p)
{
    capn_resolve(&p);
    {
      s->max_mpath_configured = capn_read32(p, 8);
      bgp_vrf_maximum_paths_set(s);
    }
    {
      struct ecommunity * rt_import;
      
    {
        capn_ptr tmp_p = capn_getp(p, 0, 1);
        capn_list64 listptr = { .p = capn_getp(tmp_p, 0, 1) };
        size_t listsize = capn_len(listptr);
        uint64_t buf[listsize];
        capn_getv64(listptr, 0, buf, listsize);
        rt_import = ecommunity_parse ((uint8_t *)buf, listsize * 8);
    }
    if (s->rt_import == NULL || !ecommunity_cmp (s->rt_import, rt_import))
      {
        bgp_vrf_rt_import_set(s, rt_import);
        ecommunity_unintern(&rt_import);
      }
    }
    {
      struct ecommunity * rt_export;
    {
        capn_ptr tmp_p = capn_getp(p, 1, 1);
        capn_list64 listptr = { .p = capn_getp(tmp_p, 0, 1) };
        size_t listsize = capn_len(listptr);
        uint64_t buf[listsize];
        capn_getv64(listptr, 0, buf, listsize);
        rt_export = ecommunity_parse ((uint8_t *)buf, listsize * 8);
    }
    if (s->rt_export == NULL || !ecommunity_cmp (s->rt_export, rt_export))
      {
        bgp_vrf_rt_export_set(s, rt_export);
        ecommunity_unintern(&rt_export);
      }
    }
}


struct prefix_rd qcapn_BGPVRF_get_outbound_rd(capn_ptr p)
{
    capn_resolve(&p);
    uint64_t tmp;
    struct prefix_rd tp;

    tp.family = AF_UNSPEC;
    tp.prefixlen = 64;
    tmp = capn_read64(p, 0);
    memcpy(&tp.val, &tmp, 8);
    return tp;
}

uint8_t qcapn_BGPVRF_get_layer_type(capn_ptr p)
{
    capn_resolve(&p);
    uint8_t ltype;

    ltype = capn_read8(p, 12);

    return ltype;
}

void qcapn_BGPVRFRoute_set(struct bgp_api_route *s, capn_ptr p)
{
    capn_resolve(&p);
    {
      /* MISSING: prefix */
    }
    {
      /* MISSING: nexthop */
    }
    {
      /* MISSING: label */
    }
}


void qcapn_BGPEventVRFRoute_write(const struct bgp_event_vrf *s, capn_ptr p)
{
    uint64_t tmp;

    memcpy(&tmp,&(s->outbound_rd.val), 8);
    capn_resolve(&p);
    capn_write8(p, 0, s->announce);
    capn_write64(p, 8, tmp);
    
    {
        if (s->prefix.family == AF_INET)
          {
            capn_ptr tempptr = capn_new_struct(p.seg, 9, 0);
            capn_write8(tempptr, 0, s->prefix.family);
            capn_write8(tempptr, 1, s->prefix.prefixlen);
            capn_write32(tempptr, 2, ntohl(s->prefix.u.prefix4.s_addr));
            capn_setp(p, 0, tempptr);
          }
        else if (s->prefix.family == AF_INET6)
          {
            size_t i;
            capn_ptr tempptr = capn_new_struct(p.seg, 21, 0);
            capn_write8(tempptr, 0, s->prefix.family);
            capn_write8(tempptr, 1, s->prefix.prefixlen);

            for(i=0; i < sizeof(struct in6_addr); i++)
              capn_write8(tempptr, i + 2, s->prefix.u.prefix + i);

            capn_setp(p, 0, tempptr);
          }
        else if (s->prefix.family == AF_L2VPN)
          {
            uint8_t index = 2;

            capn_ptr tempptr = capn_new_struct(p.seg, 18, 0);
            capn_write8(tempptr, 0, s->prefix.family);
            capn_write8(tempptr, 1, s->prefix.prefixlen);
            qcapn_prefix_macip_write(tempptr, &s->prefix, &index);
            capn_setp(p, 0, tempptr);
          }
    }
    
    {
        capn_ptr tempptr = capn_new_struct(p.seg, 8, 0);
        capn_write32(tempptr, 0, ntohl(s->nexthop.s_addr));
        capn_setp(p, 1, tempptr);
    }
    {
        capn_ptr tempptr = capn_new_struct(p.seg, 12, 0);
	capn_write32(tempptr, 0, s->label);
	capn_write32(tempptr, 4, s->ethtag);
	capn_write32(tempptr, 8, s->l2label);
        capn_setp(p, 2, tempptr);
    }
    { capn_text tp = { .str = s->esi, .len = s->esi ? strlen((const char *)s->esi) : 0 }; capn_set_text(p, 3, tp); }
    { capn_text tp = { .str = s->mac_router, .len = s->mac_router ? strlen((const char *)s->mac_router) : 0 }; capn_set_text(p, 4, tp); }
}



void qcapn_BGPEventVRFRoute_set(struct bgp_event_vrf *s, capn_ptr p)
{
    capn_resolve(&p);
    {
      /* MISSING: announce */
    }
    {
      /* MISSING: outbound_rd */
    }
    {
      /* MISSING: prefix */
    }
    {
      /* MISSING: nexthop */
    }
    {
      /* MISSING: label */
    }
}


capn_ptr qcapn_new_BGPEventVRFRoute(struct capn_segment *s)
{
    return capn_new_struct(s, 16, 5);
}


void qcapn_BGPEventShut_write(const struct bgp_event_shut *s, capn_ptr p)
{
    capn_resolve(&p);
    
    {
        capn_ptr tempptr = capn_new_struct(p.seg, 8, 0);
        capn_write32(tempptr, 0, ntohl(s->peer.s_addr));
        capn_setp(p, 0, tempptr);
    }
    capn_write8(p, 0, s->type);
    capn_write8(p, 1, s->subtype);
}



void qcapn_BGPEventShut_set(struct bgp_event_shut *s, capn_ptr p)
{
    capn_resolve(&p);
    {
      /* MISSING: peer */
    }
    {
      /* MISSING: type */
    }
    {
      /* MISSING: subtype */
    }
}


capn_ptr qcapn_new_BGPEventShut(struct capn_segment *s)
{
    return capn_new_struct(s, 8, 1);
}

