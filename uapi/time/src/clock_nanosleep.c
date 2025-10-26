/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <time.h>
#include <errno.h>
#include <assert.h>

int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec* req, struct timespec* rem)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
