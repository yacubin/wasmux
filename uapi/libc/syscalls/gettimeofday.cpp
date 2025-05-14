/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <sys/time.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __gettimeofday(struct timeval* tv, struct timezone* tz)
{
  auto ret = __DO_SYSCALL(gettimeofday, tv, tz);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__gettimeofday, gettimeofday) __ATTR_WEAK;
