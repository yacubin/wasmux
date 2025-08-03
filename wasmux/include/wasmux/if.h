/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_IF_H
#define _WASMUX_IF_H

#include <wasmux/socket.h>

enum {
  IFF_UP = 1 << 0,
#define IFF_UP IFF_UP

  IFF_LOOPBACK = 1 << 3,
#define IFF_LOOPBACK IFF_LOOPBACK

  IFF_RUNNING = 1 << 6,
#define IFF_RUNNING IFF_RUNNING

};

#define IFHWADDRLEN 6
#define IFNAMSIZ 16

struct ifmap {
  unsigned long mem_start;
  unsigned long mem_end;
  unsigned short base_addr; 
  unsigned char irq;
  unsigned char dma;
  unsigned char port;
  /* 3 bytes spare */
};

struct ifreq {
  union {
    char ifrn_name[IFNAMSIZ];
  } ifr_ifrn;

  union {
    struct sockaddr ifru_addr;
    struct sockaddr ifru_dstaddr;
    struct sockaddr ifru_broadaddr;
    struct sockaddr ifru_netmask;
    struct sockaddr ifru_hwaddr;
    short int ifru_flags;
    int ifru_ivalue;
    int ifru_mtu;
    struct ifmap ifru_map;
    char ifru_slave[IFNAMSIZ];
    char ifru_newname[IFNAMSIZ];
    void* ifru_data;
  } ifr_ifru;
};

#define ifr_name  ifr_ifrn.ifrn_name
#define ifr_addr  ifr_ifru.ifru_addr
#define ifr_flags ifr_ifru.ifru_flags

#endif /* _WASMUX_IF_H */
