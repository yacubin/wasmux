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
int __execve(const char* path, char* const argv[], char* const envp[])
{
  auto ret = __DO_SYSCALL(execve, path, argv, envp);
  __set_local_errno(-static_cast<int>(ret));
  return -1;
}

__EXPORT __ATTR_WEAK_ALIAS(__execve, execve);
