/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

#include <errno.h>

__EXPORT
__ATTR_HIDDEN int __close(int fd)
{
  int ret = static_cast<int>(__DO_SYSCALL(close, fd));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

__EXPORT
__ATTR_ALIAS(__close, close) __ATTR_WEAK;
