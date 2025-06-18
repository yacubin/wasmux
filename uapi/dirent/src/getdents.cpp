/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>

#include <dirent.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __getdents(int fd, struct dirent* dir_list, size_t count)
{
  auto ret = static_cast<int>(__DO_SYSCALL(getdents, fd, dir_list, count));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__getdents, getdents) __ATTR_WEAK;
