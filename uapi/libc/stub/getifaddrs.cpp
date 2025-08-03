/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <ifaddrs.h>
#include <assert.h>

int getifaddrs(struct ifaddrs** ifap)
{
  assert(0);
  return -1;
}

void freeifaddrs(struct ifaddrs* ifp)
{
  assert(0);
}
