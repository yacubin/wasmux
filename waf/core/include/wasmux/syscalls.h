/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SYSCALLS_H
#define _WASMUX_SYSCALLS_H

#ifdef __cplusplus
extern "C" {
#endif

#define WX_SYSCALL_NAME0 "_syscall0"
#define WX_SYSCALL_NAME1 "_syscall1"
#define WX_SYSCALL_NAME2 "_syscall2"
#define WX_SYSCALL_NAME3 "_syscall3"
#define WX_SYSCALL_NAME4 "_syscall4"
#define WX_SYSCALL_NAME5 "_syscall5"
#define WX_SYSCALL_NAME6 "_syscall6"

#ifdef __wasm__
__attribute__((export_name(WX_SYSCALL_NAME0)))
#endif
long __kernel_syscall0(long number);

#ifdef __wasm__
__attribute__((export_name(WX_SYSCALL_NAME1)))
#endif
long __kernel_syscall1(long number, long arg1);

#ifdef __wasm__
__attribute__((export_name(WX_SYSCALL_NAME2)))
#endif
long __kernel_syscall2(long number, long arg1, long arg2);

#ifdef __wasm__
__attribute__((export_name(WX_SYSCALL_NAME3)))
#endif
long __kernel_syscall3(long number, long arg1, long arg2, long arg3);

#ifdef __wasm__
__attribute__((export_name(WX_SYSCALL_NAME4)))
#endif
long __kernel_syscall4(long number, long arg1, long arg2, long arg3, long arg4);

#ifdef __wasm__
__attribute__((export_name(WX_SYSCALL_NAME5)))
#endif
long __kernel_syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5);

#ifdef __wasm__
__attribute__((export_name(WX_SYSCALL_NAME6)))
#endif
long __kernel_syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_SYSCALLS_H */
