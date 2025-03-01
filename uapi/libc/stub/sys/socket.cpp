/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/socket.h>
#include <assert.h>

int socket(int domain, int type, int protocol)
{
  assert(0);
  return -1;
}

int socketpair(int domain, int type, int protocol, int fds[2])
{
  assert(0);
  return -1;
}

int connect(int sock, const struct sockaddr* addr, socklen_t addrlen)
{
  assert(0);
  return -1;
}

int bind(int sock, const struct sockaddr* addr, socklen_t addrlen)
{
  assert(0);
  return -1;
}

int listen(int sock, int backlog)
{
  assert(0);
  return -1;
}

int accept(int sock, struct sockaddr* addr, socklen_t* addrlen)
{
  assert(0);
  return -1;
}

int accept4(int sock, struct sockaddr* addr, socklen_t* addrlen, int flags)
{
  assert(0);
  return -1;
}

ssize_t recv(int sock, void* buf, size_t len, int flags)
{
  assert(0);
  return -1;
}

ssize_t send(int sock, const void* buf, size_t len, int flags)
{
  assert(0);
  return -1;
}

ssize_t recvfrom(int sock, void* data, size_t size, int flags, struct sockaddr* addr, socklen_t* addrlen)
{
  assert(0);
  return -1;
}

ssize_t sendto(int sock, const void* data, size_t size, int flags, const struct sockaddr* addr, socklen_t addrlen)
{
  assert(0);
  return -1;
}

ssize_t recvmsg(int sock, struct msghdr* message, int flags)
{
  assert(0);
  return -1;
}

ssize_t sendmsg(int sock, const struct msghdr* message, int flags)
{
  assert(0);
  return -1;
}

int getpeername(int sock, struct sockaddr* addr, socklen_t* addrlen)
{
  assert(0);
  return -1;
}

int getsockname(int sock, struct sockaddr* addr, socklen_t* addrlen)
{
  assert(0);
  return -1;
}

int shutdown(int sock, int how)
{
  assert(0);
  return -1;
}

int getsockopt(int sock, int level, int name, void* data, socklen_t* size)
{
  assert(0);
  return -1;
}

int setsockopt(int sock, int level, int name, const void* data, socklen_t size)
{
  assert(0);
  return -1;
}
