/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <wasmux/notify_waiter.h>

#include <wasmux/platform.h>
#include <wasmux/assert.h>

void notify_waiter_init(notify_waiter_t* thiz)
{
  thiz->flag = 0;
}

int notify_waiter_wait(notify_waiter_t* thiz, int milliseconds)
{
#ifdef WA_CPU_WASM
  long long timeout;
  if (NOTIFY_WAITER_INFINITE == milliseconds)
    timeout = -1;
  else
    timeout = milliseconds * 1000000ll;
  __builtin_wasm_memory_atomic_wait32(&thiz->flag, 0, timeout);
  WA_ASSERT(thiz->flag != 0);
  thiz->flag = 0;

  return 0;

#else
  return -1;

#endif

}

int notify_waiter_notify(notify_waiter_t* thiz)
{
#ifdef WA_CPU_WASM
  thiz->flag = 1;
  __builtin_wasm_memory_atomic_notify(&thiz->flag, 1);
  return 0;

#else
  return -1;

#endif
}
