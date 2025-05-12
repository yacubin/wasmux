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
extern "C" int __mount(const char* special, const char* dir, const char* fstype, unsigned long flags, const void* data)
{
  auto ret = __DO_SYSCALL(mount, special, dir, fstype, flags, data);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__mount, mount) __ATTR_WEAK;
