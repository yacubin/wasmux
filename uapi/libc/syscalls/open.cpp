/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <kernel/compiler.h>
#include <kernel/stdarg.h>
#include <kernel/thread_data.h>
#include <kernel/syscalls.h>

__ATTR_HIDDEN
extern "C" int __open(const char* path, int flags, ...)
{
  int ret;
  umode_t mode;

  va_list args;
  va_start(args, flags);
  mode = static_cast<umode_t>(va_arg(args, unsigned));
  va_end(args);

  ret = static_cast<int>(sys_open(path, flags, mode));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__open, open) __ATTR_WEAK;
