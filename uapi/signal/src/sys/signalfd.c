/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/signalfd.h>
#include <assert.h>
#include <errno.h>

int signalfd(int fd, const sigset_t* mask, int flags)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}
