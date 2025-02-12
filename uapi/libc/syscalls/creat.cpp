/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/thread_data.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" int __creat(const char* path, mode_t mode)
{
  int ret = static_cast<int>(sys_creat(path, static_cast<umode_t>(mode)));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__creat, creat) __ATTR_WEAK;
