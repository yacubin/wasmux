/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/types.h>

#ifdef __wasm__

#ifndef __wasm_atomics__
# error implementation requires -matomics flag
#endif

.hidden __mutex_trylock
.globl __mutex_trylock
__mutex_trylock:
  .functype __mutex_trylock (PTR) -> (i32)
  local.get 0
  i32.const 0
  i32.const 1
  i32.atomic.rmw.cmpxchg 0
  i32.eqz
  end_function

.hidden __mutex_lock
.globl __mutex_lock
__mutex_lock:
  .functype __mutex_lock (PTR) -> ()
  block
    loop
      local.get 0
      call __mutex_trylock
      br_if 1
      local.get 0
      i32.const 1
      i64.const -1
      memory.atomic.wait32 0
      drop
      br 0
    end_loop
  end_block
  end_function

.hidden __mutex_unlock
.globl __mutex_unlock
__mutex_unlock:
  .functype __mutex_unlock (PTR) -> ()
  local.get 0
  i32.const 0
  i32.atomic.store 0
  local.get 0
  i32.const 1
  memory.atomic.notify 0
  drop
  end_function

#endif /* __wasm__ */
