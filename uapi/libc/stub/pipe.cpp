/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <unistd.h>
#include <assert.h>
#include <errno.h>

int pipe(int fds[2])
{
  errno = ENOSYS;
  assert(0);
  return -1;
}

int pipe2(int fds[2], int flags)
{
  errno = ENOSYS;
  assert(0);
  return -1;
}
