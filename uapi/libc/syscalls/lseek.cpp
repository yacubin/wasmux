/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <unistd.h>
#include <errno.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" off_t __lseek(int fd, off_t offset, int whence)
{
  loff_t result;
  auto ret = sys_llseek(static_cast<unsigned>(fd), static_cast<uint64_t>(offset) >> 32, offset, &result, whence);
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
