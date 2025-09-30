/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

#include <unistd.h>
#include <errno.h>

__EXPORT __ATTR_HIDDEN
int __dup2(int oldfd, int newfd)
{
  int ret = static_cast<int>(__DO_SYSCALL(dup2, oldfd, newfd));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__dup2, dup2);
