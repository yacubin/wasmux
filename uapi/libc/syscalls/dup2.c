/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <errno.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

__EXPORT __ATTR_HIDDEN
int __dup2(int oldfd, int newfd)
{
  long ret = (int)__DO_SYSCALL(dup2, oldfd, newfd);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__dup2, dup2);
