/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/stat.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT int __mknod(const char* path, mode_t mode, dev_t dev)
{
  long ret = __DO_SYSCALL(mknod, path, mode, dev);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__mknod, mknod);
