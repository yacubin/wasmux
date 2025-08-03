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

WASMUX_KERNEL_EXPORT(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL)
long __kernel_syscall(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#endif /* WASMUX_KERNEL_EXPORT */

__EXPORT_END

#endif /* _WASMUX_SYSCALLS_H */
