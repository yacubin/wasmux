/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <netdb.h>
#include <assert.h>

int h_errno = 0;

struct servent* getservbyname(const char* name, const char* proto)
{
  assert(0);
  return nullptr;
}

struct hostent* gethostbyname(const char* name)
{
  assert(0);
  return nullptr;
}

int getaddrinfo(const char* node, const char* service,
                const struct addrinfo* hints, struct addrinfo** buf)
{
  assert(0);
  return -1;
}

void freeaddrinfo(struct addrinfo* buf)
{
  assert(0);
}

const char* gai_strerror(int error_code)
{
  assert(0);
  return nullptr;
}

int getnameinfo(const struct sockaddr* addr, socklen_t addrlen, char* host,
                size_t hostlen, char* serv, size_t servlen, int flags)
{
  assert(0);
  return -1;
}

struct servent* getservbyport(int port, const char* proto)
{
  assert(0);
  return nullptr;
}
