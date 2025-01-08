/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <netdb.h>

#include <wasmux/assert.h>

int h_errno = 0;

struct servent* getservbyname(const char* name, const char* proto)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct hostent* gethostbyname(const char* name)
{
  WA_UNREACHABLE();
  return nullptr;
}

int getaddrinfo(const char* node, const char* service,
                const struct addrinfo* hints, struct addrinfo** buf)
{
  WA_UNREACHABLE();
  return -1;
}

void freeaddrinfo(struct addrinfo* buf)
{
  WA_UNREACHABLE();
}

const char* gai_strerror(int error_code)
{
  WA_UNREACHABLE();
  return nullptr;
}

int getnameinfo(const struct sockaddr* addr, socklen_t addrlen, char* host,
                size_t hostlen, char* serv, size_t servlen, int flags)
{
  WA_UNREACHABLE();
  return -1;
}
