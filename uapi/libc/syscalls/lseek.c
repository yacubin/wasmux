/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT off_t __lseek(int fd, off_t offset, int whence)
{
  loff_t result;
  long ret = __DO_SYSCALL(_llseek, fd, ((uint64_t)offset) >> 32, ((uint32_t)offset), &result, whence);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  off_t res = (off_t)ret;
  if (res != result) {
    __set_local_errno(EOVERFLOW);
    return -1;
  }

  return res;
}

__EXPORT __ATTR_WEAK_ALIAS(__lseek, lseek);
