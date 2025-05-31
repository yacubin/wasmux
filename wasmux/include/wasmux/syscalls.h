/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SYSCALLS_H
#define _WASMUX_SYSCALLS_H

#include <wasmux/export.h>
#include <wasmux/compiler.h>
#include <wasmux/wainst_names.h>
#include <wasmux/arch/unistd.h>
#include <wasmux/arch/syscalls.h>

__EXPORT_BEGIN

#ifdef __ARCH_WANT_EXPORT_SYSCALLS
#define WASMUX_KERNEL_EXPORT(module, name) __ATTR_EXPORT_NAME(name)
#endif

#ifdef __ARCH_WANT_IMPORT_SYSCALLS
#define WASMUX_KERNEL_EXPORT(module, name) __ATTR_IMPORT_NAME(module, name)
#endif

#ifdef WASMUX_KERNEL_EXPORT

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL0)
long __kernel_syscall0(long number);

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL1)
long __kernel_syscall1(long number, long arg1);

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL2)
long __kernel_syscall2(long number, long arg1, long arg2);

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL3)
long __kernel_syscall3(long number, long arg1, long arg2, long arg3);

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL4)
long __kernel_syscall4(long number, long arg1, long arg2, long arg3, long arg4);

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL5)
long __kernel_syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5);

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL6)
long __kernel_syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#endif /* WASMUX_KERNEL_EXPORT */

__EXPORT_END

#endif /* _WASMUX_SYSCALLS_H */
