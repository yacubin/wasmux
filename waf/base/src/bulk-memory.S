/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/types.h>

#ifdef __wasm__

#ifndef __wasm_bulk_memory__
# error implementation requires -mbulk-memory flag
#endif

.hidden kernel_memory_copy
.globl kernel_memory_copy
kernel_memory_copy:
  .functype kernel_memory_copy (PTR, PTR, PTR) -> (PTR)
  local.get 0
  local.get 1
  local.get 2
  memory.copy 0, 0
  local.get 0
  end_function

.hidden kernel_memory_fill
.globl kernel_memory_fill
kernel_memory_fill:
  .functype kernel_memory_fill (PTR, i32, PTR) -> (PTR)
  local.get 0
  local.get 1
  local.get 2
  memory.fill 0
  local.get 0
  end_function

#endif /* __wasm__ */
