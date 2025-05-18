/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <sys/wait.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" pid_t __waitpid(pid_t pid, int* stat_loc, int options)
{
  auto ret = __DO_SYSCALL(waitpid, pid, stat_loc, options);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__waitpid, waitpid) __ATTR_WEAK;
