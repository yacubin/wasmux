/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/select.h>
#include <assert.h>
#include <errno.h>

int select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, struct timeval* timeout)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int pselect(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const struct timespec* timeout, const sigset_t* sigmask)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
