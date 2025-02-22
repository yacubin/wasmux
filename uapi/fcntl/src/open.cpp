/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

int __open(const char* path, int flags, ...)
{
  int ret;
  mode_t mode;

  va_list args;
  va_start(args, flags);
  mode = va_arg(args, mode_t);
  va_end(args);

  ret = static_cast<int>(__SYSCALL(open, path, flags, mode));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

__ATTR_ALIAS(__open, open) __ATTR_WEAK;
