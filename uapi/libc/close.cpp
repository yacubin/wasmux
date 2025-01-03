/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <kernel/types.h>
#include <kernel/compiler.h>
#include <kernel/thread_data.h>
#include <kernel/syscalls.h>

__ATTR_HIDDEN
extern "C" int __close(int fd)
{
  int ret = static_cast<int>(sys_close(fd));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__close, close) __ATTR_WEAK;
