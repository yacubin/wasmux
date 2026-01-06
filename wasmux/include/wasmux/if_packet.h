/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_IF_PACKET_H
#define _WASMUX_IF_PACKET_H

struct sockaddr_ll {
  unsigned short sll_family;
  unsigned short sll_protocol;
  int            sll_ifindex;
  unsigned short sll_hatype;
  unsigned char  sll_pkttype;
  unsigned char  sll_halen;
  unsigned char  sll_addr[8];
};

#define PACKET_HOST 0

#endif /* _WASMUX_IF_PACKET_H */
