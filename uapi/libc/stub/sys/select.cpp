/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/select.h"

#include <wasmux/assert.h>
#include <errno.h>

int select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, struct timeval* timeout)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int pselect(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const struct timespec* timeout, const sigset_t* sigmask)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
