/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <asm/syscalls.h>
#include <sys/stat.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __mknod(const char* path, mode_t mode, dev_t dev)
{
  auto ret = __DO_SYSCALL(mknod, path, mode, dev);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__mknod, mknod) __ATTR_WEAK;
