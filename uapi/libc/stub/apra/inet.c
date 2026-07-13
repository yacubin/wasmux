/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
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

in_addr_t inet_network(const char* addr)
{
  assert(0);
  return -1;
}

int inet_aton(const char* addr, struct in_addr* in)
{
  assert(0);
  return 0;
}

struct in_addr inet_makeaddr(in_addr_t net, in_addr_t host)
{
  struct in_addr in = { 0 };
  assert(0);
  return in;
}

in_addr_t inet_lnaof(struct in_addr in)
{
  assert(0);
  return -1;
}
