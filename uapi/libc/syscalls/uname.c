/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/utsname.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT int __uname(struct utsname* buf)
{
  long ret = __DO_SYSCALL(uname, buf);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return (int)ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__uname, uname);
