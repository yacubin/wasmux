/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <bits/syscalls.h>
#include <sched.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __sched_get_priority_max(int policy)
{
  auto ret = static_cast<int>(__DO_SYSCALL(sched_get_priority_max, policy));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__sched_get_priority_max, sched_get_priority_max) __ATTR_WEAK;
