/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <arpa/inet.h>
#include <stddef.h>
#include <assert.h>

char* inet_ntoa(struct in_addr in)
{
  assert(0);
  return NULL;
}

const char* inet_ntop(int af, const void* addr, char* buf, socklen_t len)
{
  assert(0);
  return NULL;
}

int inet_pton(int af, const char* src, void* dst)
{
  assert(0);
  return -1;
}

in_addr_t inet_addr(const char* addr)
{
  assert(0);
  return -1;
}
