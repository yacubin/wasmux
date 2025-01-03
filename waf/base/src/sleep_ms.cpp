/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/sleep_ms.h>

void kernel_sleep_ms(int ms)
{
#ifdef __wasm__
# define INIT_IDLE_VAL (0)
  static int s_wait_idel_val = { INIT_IDLE_VAL };
  long long timeout = ms * 1000000ll;
  __builtin_wasm_memory_atomic_wait32(&s_wait_idel_val, INIT_IDLE_VAL, timeout);
#endif
}
