/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <sys/utsname.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __uname(struct utsname* buf)
{
  auto ret = __DO_SYSCALL(uname, buf);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return static_cast<int>(ret);
}

extern "C" __ATTR_ALIAS(__uname, uname) __ATTR_WEAK;
