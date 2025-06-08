/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _NETINET_IN_H
#define _NETINET_IN_H

#include <wasmux/types.h>
#include <wasmux/socket.h>
#include <wasmux/byteorder.h>

typedef uint32_t in_addr_t;

#define INADDR_LOOPBACK 0x7f000001U
#define INADDR_ANY      0x00000000U

enum {
  IPPROTO_IP = 0,
#define IPPROTO_IP IPPROTO_IP

  IPPROTO_TCP = 6,
#define IPPROTO_TCP IPPROTO_TCP

  IPPROTO_UDP = 17,
#define IPPROTO_UDP IPPROTO_UDP

  IPPROTO_IPV6 = 41,
#define IPPROTO_IPV6 IPPROTO_IPV6

  IPPROTO_RAW = 255,
#define IPPROTO_RAW IPPROTO_RAW
};

#define IP_TTL                    2
#define IP_RECVERR                11
#define IP_MULTICAST_IF           32
#define IP_MULTICAST_TTL          33
#define IP_MULTICAST_LOOP         34
#define IP_ADD_MEMBERSHIP         35
#define IP_DROP_MEMBERSHIP        36
#define IP_ADD_SOURCE_MEMBERSHIP  39
#define IP_DROP_SOURCE_MEMBERSHIP 40

#define IPV6_UNICAST_HOPS   16
#define IPV6_MULTICAST_HOPS 18
#define IPV6_MULTICAST_LOOP 19
#define IPV6_JOIN_GROUP     20
#define IPV6_LEAVE_GROUP    21
#define IPV6_RECVERR        25
#define IPV6_V6ONLY         26
#define IPV6_MULTICAST_IF   32

#define IPV6_ADD_MEMBERSHIP  IPV6_JOIN_GROUP
#define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP

struct in_addr {
  unsigned s_addr;
};

struct sockaddr_in {
  sa_family_t    sin_family;
  in_port_t      sin_port;
  struct in_addr sin_addr;
};

struct in6_addr {
  uint8_t s6_addr[16];
};

struct sockaddr_in6 {
  sa_family_t     sin6_family;
  in_port_t       sin6_port;
  uint32_t        sin6_flowinfo;
  struct in6_addr sin6_addr;
  uint32_t        sin6_scope_id;
};

#define IN6ADDR_ANY_INIT      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;

#define MCAST_JOIN_SOURCE_GROUP  46
#define MCAST_LEAVE_SOURCE_GROUP 47

struct ip_mreq {
  struct in_addr imr_multiaddr;
  struct in_addr imr_interface;
};

struct ip_mreq_source {
  struct in_addr imr_multiaddr;
  struct in_addr imr_interface;
  struct in_addr imr_sourceaddr;
};

struct group_source_req {
  uint32_t gsr_interface;
  struct sockaddr_storage gsr_group;
  struct sockaddr_storage gsr_source;
};

struct ipv6_mreq {
  struct in6_addr ipv6mr_multiaddr;
  unsigned        ipv6mr_interface;
};

#endif /* _NETINET_IN_H */
