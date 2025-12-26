/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <errno.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

__EXPORT __ATTR_HIDDEN
int __chdir(const char* path)
{
  long ret = __DO_SYSCALL(chdir, path);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__chdir, chdir);
