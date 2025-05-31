/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>

#include <sched.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __sched_get_priority_min(int policy)
{
  auto ret = static_cast<int>(__DO_SYSCALL(sched_get_priority_min, policy));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__sched_get_priority_min, sched_get_priority_min) __ATTR_WEAK;
