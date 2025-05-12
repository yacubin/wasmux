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
extern "C" ssize_t __write(int fd, const void* buf, size_t count)
{
  auto ret = __DO_SYSCALL(write, fd, buf, count);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return static_cast<ssize_t>(ret);
}

extern "C" __ATTR_ALIAS(__write, write) __ATTR_WEAK;
