/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

#include <errno.h>

__EXPORT __ATTR_HIDDEN
int __chdir(const char* path)
{
  auto ret = __DO_SYSCALL(chdir, path);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__chdir, chdir);
