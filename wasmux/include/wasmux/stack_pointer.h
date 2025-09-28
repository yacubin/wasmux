#ifndef _WASMUX_STACK_POINTER_H
#define _WASMUX_STACK_POINTER_H

#include <wasmux/platform.h>

static inline void* __get_stack_pointer()
{
  void* stack;
#ifdef WA_CPU_WASM
  asm("global.get __stack_pointer\n"
      "local.set %0" : "=r" (stack));
#elif __x86_64__
  asm("mov %%rsp, %0" : "=r" (stack));
#else
  asm("mov %%esp, %0" : "=r" (stack));
#endif
  return stack;
}

static inline void __set_stack_pointer(void* stack)
{
#ifdef WA_CPU_WASM
  asm("local.get 0\n"
      "global.set __stack_pointer");
#else
#endif
}

#endif /* _WASMUX_STACK_POINTER_H */
