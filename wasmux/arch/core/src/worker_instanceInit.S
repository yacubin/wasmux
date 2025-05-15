/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux/types.h>

#ifdef __wasm__

.globaltype __stack_pointer, PTR

.section .text,"",@
.globl WebWorkerInstanceInit
.hidden WebWorkerInstanceInit
WebWorkerInstanceInit:
  .functype WebWorkerInstanceInit (PTR) -> ()

  local.get 0
  global.set __stack_pointer

  .functype __start_worker () -> ()
  call __start_worker

  end_function

#endif
