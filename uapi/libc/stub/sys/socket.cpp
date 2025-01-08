/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/socket.h"

#include <wasmux/assert.h>

int socket(int domain, int type, int protocol)
{
  WA_UNREACHABLE();
  return -1;
}

int connect(int sock, const struct sockaddr* addr, socklen_t addrlen)
{
  WA_UNREACHABLE();
  return -1;
}

int bind(int sock, const struct sockaddr* addr, socklen_t addrlen)
{
  WA_UNREACHABLE();
  return -1;
}

int listen(int sock, int backlog)
{
  WA_UNREACHABLE();
  return -1;
}

int accept(int sock, struct sockaddr* addr, socklen_t* addrlen)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t recv(int sock, void* buf, size_t len, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t send(int sock, const void* buf, size_t len, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t recvfrom(int sock, void* data, size_t size, int flags, struct sockaddr* addr, socklen_t* addrlen)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t sendto(int sock, const void* data, size_t size, int flags, const struct sockaddr* addr, socklen_t addrlen)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t recvmsg(int sock, struct msghdr* message, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t sendmsg(int sock, const struct msghdr* message, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

int getpeername(int sock, struct sockaddr* addr, socklen_t* addrlen)
{
  WA_UNREACHABLE();
  return -1;
}

int getsockname(int sock, struct sockaddr* addr, socklen_t* addrlen)
{
  WA_UNREACHABLE();
  return -1;
}

int shutdown(int sock, int how)
{
  WA_UNREACHABLE();
  return -1;
}

int getsockopt(int sock, int level, int name, void* data, socklen_t* size)
{
  WA_UNREACHABLE();
  return -1;
}

int setsockopt(int sock, int level, int name, const void* data, socklen_t size)
{
  WA_UNREACHABLE();
  return -1;
}
