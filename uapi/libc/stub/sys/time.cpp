/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <sys/time.h>

#include <wasmux/compiler.h>
#include <wasmux/assert.h>
#include <errno.h>

static char __tzname_GMT[] = "GMT";
extern "C" char* __tzname[2] =
{
  __tzname_GMT,
  __tzname_GMT,
};

extern "C" __ATTR_ALIAS(__tzname, tzname) __ATTR_WEAK;

int utimes(const char* filename, const struct timeval times[2])
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
