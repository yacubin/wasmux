/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <poll.h>
#include <assert.h>
#include <errno.h>

int poll(struct pollfd* fds, nfds_t nfds, int timeout)
{
  errno = ENOSYS;
  assert(0);
  return -1;
}
