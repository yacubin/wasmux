/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/timerfd.h>
#include <errno.h>
#include <assert.h>

int timerfd_create(int clock_id, int flags)
{
  assert(0);
  return -1;
}

int timerfd_gettime(int fd, struct itimerspec* cur_its)
{
  assert(0);
  return -1;
}

int timerfd_settime(int ufd, int flags, const struct itimerspec* new_its, struct itimerspec* old_its)
{
  assert(0);
  return -1;
}
