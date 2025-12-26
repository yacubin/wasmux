/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdarg.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT int __ioctl(int fd, int request, ...)
{
  va_list args;
  va_start(args, request);
  void* arg = va_arg(args, void*);
  va_end(args);

  long ret = __DO_SYSCALL(ioctl, fd, request, args);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__ioctl, ioctl);
