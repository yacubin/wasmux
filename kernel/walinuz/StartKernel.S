#include <wasmux/types.h>

.globaltype __stack_pointer, PTR

/*
  * The stack cannot point to the top because of receiving
  * a worker instance at the bottom of the stack
  * __stack_pointer & WASM_MEMORY_PAGE_MASK
  */

.section .text,"",@
.globl _start_kernel
.type _start_kernel,@function
_start_kernel:
  .functype _start_kernel () -> ()

  global.get __stack_pointer
  PTR.const PTR_SIZE
  PTR.sub
  global.set __stack_pointer

  .functype __start_kernel () -> ()
  call __start_kernel

  end_function
