/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <bits/syscalls.h>
#include <unistd.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __dup2(int oldfd, int newfd)
{
  int ret = static_cast<int>(__DO_SYSCALL(dup2, oldfd, newfd));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__dup2, dup2) __ATTR_WEAK;
