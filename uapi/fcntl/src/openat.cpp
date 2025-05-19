/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>

#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>

int __openat(int dirfd, const char* path, int flags, ...)
{
  mode_t mode;

  if ((flags & O_CREAT) || (flags & O_TMPFILE) == O_TMPFILE) {
    va_list args;
    va_start(args, flags);
    mode = va_arg(args, mode_t);
    va_end(args);
  }
  else {
    mode = 0;
  }

  auto ret = static_cast<int>(__DO_SYSCALL(openat, dirfd, path, flags, mode));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

__ATTR_ALIAS(__openat, openat) __ATTR_WEAK;
