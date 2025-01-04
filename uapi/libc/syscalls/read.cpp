/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <kernel/types.h>
#include <kernel/compiler.h>
#include <kernel/thread_data.h>
#include <kernel/syscalls.h>

__ATTR_HIDDEN
extern "C" ssize_t __read(int fd, void* buf, size_t count)
{
  long ret = sys_read(static_cast<unsigned>(fd), reinterpret_cast<char*>(buf), count);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return static_cast<ssize_t>(ret);
}

extern "C" __ATTR_ALIAS(__read, read) __ATTR_WEAK;
