/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stddef.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT char* __getcwd(char* buf, size_t size)
{
  long ret = __DO_SYSCALL(getcwd, buf, size);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return NULL;
  }

  return buf;
}

__EXPORT __ATTR_WEAK_ALIAS(__getcwd, getcwd);
