/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/time.h"

#include <kernel/assert.h>
#include <errno.h>

int gettimeofday(struct timeval* tv, struct timezone* tz)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int utimes(const char* filename, const struct timeval times[2])
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
