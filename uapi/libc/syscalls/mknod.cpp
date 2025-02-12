/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/stat.h>
#include <wasmux/compiler.h>
#include <wasmux/thread_data.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" int __mknod(const char* path, mode_t mode, dev_t dev)
{
  auto ret = sys_mknod(path, static_cast<umode_t>(mode), dev);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__mknod, mknod) __ATTR_WEAK;
