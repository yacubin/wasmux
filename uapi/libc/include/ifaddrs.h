/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _IFADDRS_H
#define _IFADDRS_H

#include <wasmux/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ifaddrs {
  struct ifaddrs*  ifa_next;        // Pointer to the next structure
  char*            ifa_name;        // Interface name (e.g., "eth0")
  unsigned         ifa_flags;       // Interface flags (e.g., IFF_UP, IFF_LOOPBACK)
  struct sockaddr* ifa_addr;        // Primary address of the interface
  struct sockaddr* ifa_netmask;     // Netmask of the interface

  union {
    struct sockaddr* ifu_broadaddr; // Broadcast address (for broadcast-capable interfaces)
    struct sockaddr* ifu_dstaddr;   // Destination address (broadcast or peer)
  } ifa_ifu;

#ifndef ifa_broadaddr
# define ifa_broadaddr ifa_ifu.ifu_broadaddr
#endif

#ifndef ifa_dstaddr
# define ifa_dstaddr ifa_ifu.ifu_dstaddr
#endif

  void*            ifa_data;        // Optional data (depends on platform)
};

int getifaddrs(struct ifaddrs** ifap);
void freeifaddrs(struct ifaddrs* ifp);

#ifdef __cplusplus
}
#endif

#endif /* _IFADDRS_H */
