/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/uio.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT ssize_t __readv(int fd, const struct iovec* iov, int count)
{
  long ret = __DO_SYSCALL(readv, fd, iov, count);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return (ssize_t)ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__readv, readv);
