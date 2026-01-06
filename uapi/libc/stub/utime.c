/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <utime.h>
#include <assert.h>
#include <errno.h>

int utime(const char* filename, const struct utimbuf* times)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
