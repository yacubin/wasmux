/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/epoll.h>
#include <errno.h>
#include <assert.h>

int epoll_create1(int flags)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int epoll_ctl(int epfd, int op, int fd, struct epoll_event* event)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int epoll_wait(int epfd, struct epoll_event* events, int maxevents, int timeout)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
