/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/init.h>
#include <wasmux/log.h>
#include <wasmux/main_thread.h>
#include <wasmux/memory_alloc.h>

extern "C" void __start_kernel()
{
  WEI::mainThreadInit();
  WebMemoryAllocInit();

  if (__start_initcall_main) {
    const kernel_initcall_t* fn = (const kernel_initcall_t*)&__start_initcall_main;
    while (fn < (const kernel_initcall_t*)&__stop_initcall_main) {
      int ret = (*fn)();
      if (ret) {
        LOG_ERROR("Initialization of the %p function returned %i error code", *fn, ret);
        // TODO: Exception
        return;
      }
      fn++;
    }
  }
  // TODO: Move to StartWorker
  if (__wasm_call_ctors) {
    __wasm_call_ctors();
  }
}
