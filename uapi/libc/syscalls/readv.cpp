/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <bits/syscalls.h>
#include <sys/uio.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" ssize_t __readv(int fd, const struct iovec* iov, int count)
{
  auto ret = __DO_SYSCALL(readv, fd, iov, count);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return static_cast<ssize_t>(ret);
}

extern "C" __ATTR_ALIAS(__readv, readv) __ATTR_WEAK;
