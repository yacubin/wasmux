/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include "net1.h"

int net1_socket(int family, int type, int protocol)
{
  return -1;
}

int net1_close(int fd)
{
  return 0;
}

int net1_bind(int fd, struct sockaddr* addr, int addrlen)
{
  return -1;
}

int net1_listen(int fd, int backlog)
{
  return -1;
}

int net1_recv(int fd, void* buf, size_t size, unsigned flags)
{
  return -1;
}

int net1_send(int fd, const void* buf, size_t len, unsigned flags)
{
  return -1;
}
