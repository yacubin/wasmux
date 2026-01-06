/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sched.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT int __sched_get_priority_max(int policy)
{
  long ret = __DO_SYSCALL(sched_get_priority_max, policy);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__sched_get_priority_max, sched_get_priority_max);
