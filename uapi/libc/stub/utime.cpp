/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "utime.h"

#include <wasmux/assert.h>
#include <errno.h>

int utime(const char* filename, const struct utimbuf* times)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
