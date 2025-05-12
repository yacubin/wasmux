/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <bits/syscalls.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __close(int fd)
{
  int ret = static_cast<int>(__DO_SYSCALL(close, fd));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__close, close) __ATTR_WEAK;
