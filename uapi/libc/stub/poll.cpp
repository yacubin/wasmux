/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <poll.h>
#include <wasmux/assert.h>
#include <errno.h>

int poll(struct pollfd* fds, nfds_t nfds, int timeout)
{
  errno = ENOSYS;
  WA_UNREACHABLE();
  return -1;
}
