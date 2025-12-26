/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <errno.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

__EXPORT __ATTR_HIDDEN
int __execve(const char* path, char* const argv[], char* const envp[])
{
  long ret = __DO_SYSCALL(execve, path, argv, envp);
  __set_local_errno(-((int)ret));
  return -1;
}

__EXPORT __ATTR_WEAK_ALIAS(__execve, execve);
