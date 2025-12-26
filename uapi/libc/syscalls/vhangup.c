/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT int __vhangup(void)
{
  long ret = __DO_SYSCALL(vhangup);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__vhangup, vhangup);
