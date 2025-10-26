/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <time.h>
#include <errno.h>
#include <assert.h>

int clock_getres(clockid_t clock_id, struct timespec* ts)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
