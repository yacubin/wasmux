/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/init.h>
#include <wasmux/log.h>

extern "C" void __start_worker()
{
  if (__start_initcall_worker) {
    const kernel_initcall_t* fn = (const kernel_initcall_t*)&__start_initcall_worker;
    while (fn < (const kernel_initcall_t*)&__stop_initcall_worker) {
      int ret = (*fn)();
      if (ret) {
        LOG_ERROR("Initialization of the %p function returned %i error code", *fn, ret);
        // TODO: Exception
        return;
      }
      fn++;
    }
  }
}
