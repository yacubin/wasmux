/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/mount.h>
#include <errno.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" int __umount(const char* special)
{
  auto ret = __DO_SYSCALL(umount2, special, 0);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__umount, umount) __ATTR_WEAK;
