/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <errno.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

__EXPORT __ATTR_HIDDEN
int __close(int fd)
{
  long ret = (int)__DO_SYSCALL(close, fd);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__close, close);
