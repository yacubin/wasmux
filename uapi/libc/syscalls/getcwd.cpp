/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/compiler.h>
#include <wasmux/thread_data.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" char* __getcwd(char* buf, size_t size)
{
  long ret = sys_getcwd(buf, static_cast<unsigned long>(size));
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return nullptr;
  }

  return buf;
}

extern "C" __ATTR_ALIAS(__getcwd, getcwd) __ATTR_WEAK;
