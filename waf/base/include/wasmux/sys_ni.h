#ifndef _WASMUX_SYS_NI_H
#define _WASMUX_SYS_NI_H

#include <wasmux/export.h>

__EXPORT long sys_ni_syscall0();
__EXPORT long sys_ni_syscall1(long arg1);
__EXPORT long sys_ni_syscall2(long arg1, long arg2);
__EXPORT long sys_ni_syscall3(long arg1, long arg2, long arg3);
__EXPORT long sys_ni_syscall4(long arg1, long arg2, long arg3, long arg4);
__EXPORT long sys_ni_syscall5(long arg1, long arg2, long arg3, long arg4, long arg5);
__EXPORT long sys_ni_syscall6(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#endif /* _WASMUX_SYS_NI_H */
