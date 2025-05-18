/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SYSCALLS_H
#define _WASMUX_SYSCALLS_H

#include <wasmux/compiler.h>
#include <wasmux/wainst_names.h>

#ifdef __cplusplus
extern "C" {
#endif

__ATTR_EXPORT_NAME(WASMUX_KERNEL_SYSCALL0)
long __kernel_syscall0(long number);

__ATTR_EXPORT_NAME(WASMUX_KERNEL_SYSCALL1)
long __kernel_syscall1(long number, long arg1);

__ATTR_EXPORT_NAME(WASMUX_KERNEL_SYSCALL2)
long __kernel_syscall2(long number, long arg1, long arg2);

__ATTR_EXPORT_NAME(WASMUX_KERNEL_SYSCALL3)
long __kernel_syscall3(long number, long arg1, long arg2, long arg3);

__ATTR_EXPORT_NAME(WASMUX_KERNEL_SYSCALL4)
long __kernel_syscall4(long number, long arg1, long arg2, long arg3, long arg4);

__ATTR_EXPORT_NAME(WASMUX_KERNEL_SYSCALL5)
long __kernel_syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5);

__ATTR_EXPORT_NAME(WASMUX_KERNEL_SYSCALL6)
long __kernel_syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_SYSCALLS_H */
