/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ROUTE_H
#define _WASMUX_ROUTE_H

struct rtentry {
  unsigned long rt_pad1;
  struct sockaddr rt_dst;
  struct sockaddr rt_gateway;
  struct sockaddr rt_genmask;
  unsigned short rt_flags;
  short rt_pad2;
  unsigned long rt_pad3;
  void* rt_pad4;
  short rt_metric;
  char* rt_dev;
  unsigned long rt_mtu;
  unsigned long rt_window;
  unsigned short rt_irtt;
};

#define rt_mss rt_mtu

#define RTF_UP      0x0001
#define RTF_GATEWAY 0x0002

#endif /* _WASMUX_ROUTE_H */
