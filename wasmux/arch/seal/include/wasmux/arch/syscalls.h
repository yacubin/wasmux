/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ARCH_SYSCALLS_H
#define _WASMUX_ARCH_SYSCALLS_H

#include <wasmux/arch/syscalls_define.h>
#include <wasmux/arch/arch-syscall.h>

#define __SYSCALL_ARG0(fn, a1, a2, a3, a4, a5, a6) fn()
#define __SYSCALL_ARG1(fn, a1, a2, a3, a4, a5, a6) fn((long)(a1))
#define __SYSCALL_ARG2(fn, a1, a2, a3, a4, a5, a6) fn((long)(a1), (long)(a2))
#define __SYSCALL_ARG3(fn, a1, a2, a3, a4, a5, a6) fn((long)(a1), (long)(a2), (long)(a3))
#define __SYSCALL_ARG4(fn, a1, a2, a3, a4, a5, a6) fn((long)(a1), (long)(a2), (long)(a3), (long)(a4))
#define __SYSCALL_ARG5(fn, a1, a2, a3, a4, a5, a6) fn((long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5))
#define __SYSCALL_ARG6(fn, a1, a2, a3, a4, a5, a6) fn((long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5), (long)(a6))

#define __SYSCALL_CALL(m, name, a1, a2, a3, a4, a5, a6, n, ...) \
  __SYSCALL_ARG##n(m(name), a1, a2, a3, a4, a5, a6)

#define __SC_NR_CAST(name) __SEAL_##name
#define __SR_NO_CAST(name) name

#define __DO_SYSCALL(...) __SYSCALL_CALL(__SC_NR_CAST, __VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define __SYSCALL(...) __SYSCALL_CALL(__SR_NO_CAST, __VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)

#endif /* _WASMUX_ARCH_SYSCALLS_H */
