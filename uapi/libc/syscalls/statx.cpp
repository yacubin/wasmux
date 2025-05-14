/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <sys/stat.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __statx(int dirfd, const char* path, int flags, unsigned mask, struct statx* buf)
{
  auto ret = __DO_SYSCALL(statx, dirfd, path, flags, mask, buf);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__statx, statx) __ATTR_WEAK;
