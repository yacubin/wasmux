/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <stdarg.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __ioctl(int fd, int request, ...)
{
  int ret;

  va_list args;
  va_start(args, request);
  void* arg = va_arg(args, void*);
  va_end(args);

  ret = static_cast<int>(__DO_SYSCALL(ioctl, fd, request, args));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__ioctl, ioctl) __ATTR_WEAK;
