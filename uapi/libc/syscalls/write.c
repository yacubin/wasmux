/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT ssize_t __write(int fd, const void* buf, size_t count)
{
  long ret = __DO_SYSCALL(write, fd, buf, count);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return (ssize_t)ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__write, write);
