/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/compiler.h>
#include <wasmux/thread_data.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" int __execve(const char* path, char* const argv[], char* const envp[])
{
  auto ret = sys_execve(path, argv, envp);
  __set_local_errno(-static_cast<int>(ret));
  return -1;
}

extern "C" __ATTR_ALIAS(__execve, execve) __ATTR_WEAK;
