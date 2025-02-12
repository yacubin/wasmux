/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/thread_data.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" ssize_t __read(int fd, void* buf, size_t count)
{
  auto ret = __DO_SYSCALL(read, fd, buf, count);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return static_cast<ssize_t>(ret);
}

extern "C" __ATTR_ALIAS(__read, read) __ATTR_WEAK;
