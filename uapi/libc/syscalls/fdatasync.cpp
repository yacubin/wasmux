/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>

#include <unistd.h>
#include <errno.h>
 
__ATTR_HIDDEN
extern "C" int __fdatasync(int fd)
{
  auto ret = __DO_SYSCALL(fdatasync, fd);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__fdatasync, fdatasync) __ATTR_WEAK;
