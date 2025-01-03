/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "utime.h"

#include <kernel/assert.h>
#include <errno.h>

int utime(const char* filename, const struct utimbuf* times)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
