/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <wasmux/init.h>

extern "C" void __start_kernel()
{
  if (__start_initcall_main) {
    const kernel_initcall_t* fn = (const kernel_initcall_t*)&__start_initcall_main;
    while (fn < (const kernel_initcall_t*)&__stop_initcall_main) {
      int ret = (*fn)();
      if (ret) {
        return;
      }
      fn++;
    }
  }
}
