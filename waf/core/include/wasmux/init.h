/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_INIT_H
#define _WA_KERNEL_INIT_H

#include <wasmux/compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*kernel_initcall_t) (void);
typedef void (*kernel_exitcall_t) (void);

#define __UNIQUE_INITCALL(fn, sec, level) \
  __TOKEN_CONCAT(__, \
  __TOKEN_CONCAT(sec, \
  __TOKEN_CONCAT(_, \
  __TOKEN_CONCAT(fn, \
  __TOKEN_CONCAT(_, \
  __TOKEN_CONCAT(__LINE__, \
  __TOKEN_CONCAT(_, \
  __TOKEN_CONCAT(__COUNTER__, \
  __TOKEN_CONCAT(_, level)))))))))

#define __DEFINE_INITCALL(fn, sec, level) \
  __attribute__((__section__(__STRINGIFY(sec)))) \
  kernel_initcall_t __UNIQUE_INITCALL(fn, sec, level) = &fn;

#define MAIN_INITCALL(fn) __DEFINE_INITCALL(fn, initcall_main, 0)
#define WORKER_INITCALL(fn) __DEFINE_INITCALL(fn, initcall_worker, 0)

extern const char __start_initcall_main __ATTR_WEAK;
extern const char __stop_initcall_main __ATTR_WEAK;
extern const char __start_initcall_worker __ATTR_WEAK;
extern const char __stop_initcall_worker __ATTR_WEAK;

extern void __wasm_call_ctors(void) __ATTR_WEAK;

#ifdef __cplusplus
}
#endif

#endif /* _WA_KERNEL_INIT_H */
