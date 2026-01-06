/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/time.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT int __gettimeofday(struct timeval* tv, struct timezone* tz)
{
  long ret = __DO_SYSCALL(gettimeofday, tv, tz);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__gettimeofday, gettimeofday);
