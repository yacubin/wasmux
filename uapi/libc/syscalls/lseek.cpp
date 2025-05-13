/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <asm/syscalls.h>
#include <unistd.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" off_t __lseek(int fd, off_t offset, int whence)
{
  loff_t result;
  auto ret = __DO_SYSCALL(_llseek, fd, static_cast<uint64_t>(offset) >> 32, static_cast<uint32_t>(offset), &result, whence);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  auto res = static_cast<off_t>(result);
  if (res != result) {
    __set_local_errno(EOVERFLOW);
    return -1;
  }

  return res;
}

extern "C" __ATTR_ALIAS(__lseek, lseek) __ATTR_WEAK;
