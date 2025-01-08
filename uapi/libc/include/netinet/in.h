/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_NETINET_IN_H
#define _WA_LIBC_NETINET_IN_H

#include <wasmux/types.h>
#include <wasmux/socket.h>
#include <wasmux/byteorder.h>

typedef uint32_t in_addr_t;

#define INADDR_LOOPBACK 0x7f000001U
#define INADDR_ANY      0x00000000U

enum {
  IPPROTO_TCP = 6,
#define IPPROTO_TCP IPPROTO_TCP

  IPPROTO_UDP = 17,
#define IPPROTO_UDP IPPROTO_UDP

  IPPROTO_RAW = 255,
#define IPPROTO_RAW IPPROTO_RAW
};

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

#endif /* _WA_LIBC_NETINET_IN_H */
