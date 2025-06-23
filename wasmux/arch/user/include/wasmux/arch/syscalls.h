/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ARCH_SYSCALLS_H
#define _WASMUX_ARCH_SYSCALLS_H

#include <wasmux/arch/arch-syscall.h>

#define __SC_NR_CAST(name) __NR_##name
#define __SR_NO_CAST(name) name

#define __SYSCALL_CALL(m, name, a1, a2, a3, a4, a5, a6, ...) \
  __kernel_syscall(m(name), (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5), (long)(a6))
#define __DO_SYSCALL(...) __SYSCALL_CALL(__SC_NR_CAST, __VA_ARGS__, 0l, 0l, 0l, 0l, 0l, 0l)
#define __SYSCALL(...) __SYSCALL_CALL(__SR_NO_CAST, __VA_ARGS__, 0l, 0l, 0l, 0l, 0l, 0l)

#endif /* _WASMUX_ARCH_SYSCALLS_H */
