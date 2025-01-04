/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <kernel/types.h>
#include <kernel/compiler.h>
#include <kernel/stdarg.h>
#include <kernel/thread_data.h>
#include <kernel/syscalls.h>

__ATTR_HIDDEN
extern "C" int __ioctl(int fd, int request, ...)
{
  int ret;

  va_list args;
  va_start(args, request);
  void* arg = va_arg(args, void*);
  va_end(args);

  ret = static_cast<int>(sys_ioctl(fd, static_cast<unsigned>(request), reinterpret_cast<unsigned long>(args)));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__ioctl, ioctl) __ATTR_WEAK;
