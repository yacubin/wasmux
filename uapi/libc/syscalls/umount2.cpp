/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <bits/syscalls.h>
#include <sys/mount.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __umount2(const char* special, int flags)
{
  auto ret = __DO_SYSCALL(umount2, special, flags);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__umount2, umount2) __ATTR_WEAK;
