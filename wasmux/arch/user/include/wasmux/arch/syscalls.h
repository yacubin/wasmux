/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ARCH_SYSCALLS_H
#define _WASMUX_ARCH_SYSCALLS_H

#include <wasmux/arch/arch-syscall.h>

#define __SYSCALL_ARG0(nr, a1, a2, a3, a4, a5, a6) nr
#define __SYSCALL_ARG1(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1)
#define __SYSCALL_ARG2(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2)
#define __SYSCALL_ARG3(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3)
#define __SYSCALL_ARG4(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3), (long)(a4)
#define __SYSCALL_ARG5(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5)
#define __SYSCALL_ARG6(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5), (long)(a6)

#define __SYSCALL_CALL(m, name, a1, a2, a3, a4, a5, a6, n, ...) \
  __kernel_syscall##n(__SYSCALL_ARG##n(m(name), a1, a2, a3, a4, a5, a6))

#define __SC_NR_CAST(name) __NR_##name
#define __SR_NO_CAST(name) name

#define ___DO_SYSCALL(...) __SYSCALL_CALL(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define __DO_SYSCALL(...) ___DO_SYSCALL(__SC_NR_CAST, __VA_ARGS__)
#define __SYSCALL(...) ___DO_SYSCALL(__SR_NO_CAST, __VA_ARGS__)

#endif /* _WASMUX_ARCH_SYSCALLS_H */
