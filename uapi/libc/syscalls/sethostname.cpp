/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <unistd.h>
#include <errno.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" int __sethostname(const char* name, size_t len)
{
  auto ret = __DO_SYSCALL(sethostname, name, len);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__sethostname, sethostname) __ATTR_WEAK;
