/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux/errno.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

#define __SYSCALL_DECL_x(nr, sym)
#define __SYSCALL_DECL_0(nr, sym) __EXPORT long __waml_##sym();
#define __SYSCALL_DECL_1(nr, sym) __EXPORT long __waml_##sym(long arg1);
#define __SYSCALL_DECL_2(nr, sym) __EXPORT long __waml_##sym(long arg1, long arg2);
#define __SYSCALL_DECL_3(nr, sym) __EXPORT long __waml_##sym(long arg1, long arg2, long arg3);
#define __SYSCALL_DECL_4(nr, sym) __EXPORT long __waml_##sym(long arg1, long arg2, long arg3, long arg4);
#define __SYSCALL_DECL_5(nr, sym) __EXPORT long __waml_##sym(long arg1, long arg2, long arg3, long arg4, long arg5);
#define __SYSCALL_DECL_6(nr, sym) __EXPORT long __waml_##sym(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#define __SYSCALL(nr, argc, sym) __SYSCALL_DECL_##argc(nr, sym)
#include <wasmux/syscall-list.h>

#define __SYSCALL_CALL_x(nr, sym)
#define __SYSCALL_CALL_0(nr, sym)
#define __SYSCALL_CALL_1(nr, sym)
#define __SYSCALL_CALL_2(nr, sym)
#define __SYSCALL_CALL_3(nr, sym)
#define __SYSCALL_CALL_4(nr, sym)
#define __SYSCALL_CALL_5(nr, sym)
#define __SYSCALL_CALL_6(nr, sym)

#undef __SYSCALL
#define __SYSCALL(nr, argc, sym) __SYSCALL_CALL_##argc(nr, sym)

/* Handles syscalls with 0 arguments */
#undef __SYSCALL_CALL_0
#define __SYSCALL_CALL_0(nr, sym) case nr: return __waml_##sym();
long __kernel_syscall0(long number)
{
switch (number) {
#include <wasmux/syscall-list.h>
}
return -ENOSYS;
}
#undef __SYSCALL_CALL_0
#define __SYSCALL_CALL_0(nr, sym)

/* Handles syscalls with 1 arguments */
#undef __SYSCALL_CALL_1
#define __SYSCALL_CALL_1(nr, sym) case nr: return __waml_##sym(arg1);
long __kernel_syscall1(long number, long arg1)
{
switch (number) {
#include <wasmux/syscall-list.h>
}
return -ENOSYS;
}
#undef __SYSCALL_CALL_1
#define __SYSCALL_CALL_1(nr, sym)

/* Handles syscalls with 2 arguments */
#undef __SYSCALL_CALL_2
#define __SYSCALL_CALL_2(nr, sym) case nr: return __waml_##sym(arg1, arg2);
long __kernel_syscall2(long number, long arg1, long arg2)
{
switch (number) {
#include <wasmux/syscall-list.h>
}
return -ENOSYS;
}
#undef __SYSCALL_CALL_2
#define __SYSCALL_CALL_2(nr, sym)

/* Handles syscalls with 3 arguments */
#undef __SYSCALL_CALL_3
#define __SYSCALL_CALL_3(nr, sym) case nr: return __waml_##sym(arg1, arg2, arg3);
long __kernel_syscall3(long number, long arg1, long arg2, long arg3)
{
switch (number) {
#include <wasmux/syscall-list.h>
}
return -ENOSYS;
}
#undef __SYSCALL_CALL_3
#define __SYSCALL_CALL_3(nr, sym)

/* Handles syscalls with 4 arguments */
#undef __SYSCALL_CALL_4
#define __SYSCALL_CALL_4(nr, sym) case nr: return __waml_##sym(arg1, arg2, arg3, arg4);
long __kernel_syscall4(long number, long arg1, long arg2, long arg3, long arg4)
{
switch (number) {
#include <wasmux/syscall-list.h>
}
return -ENOSYS;
}
#undef __SYSCALL_CALL_4
#define __SYSCALL_CALL_4(nr, sym)

/* Handles syscalls with 5 arguments */
#undef __SYSCALL_CALL_5
#define __SYSCALL_CALL_5(nr, sym) case nr: return __waml_##sym(arg1, arg2, arg3, arg4, arg5);
long __kernel_syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5)
{
switch (number) {
#include <wasmux/syscall-list.h>
}
return -ENOSYS;
}
#undef __SYSCALL_CALL_5
#define __SYSCALL_CALL_5(nr, sym)

/* Handles syscalls with 6 arguments */
#undef __SYSCALL_CALL_6
#define __SYSCALL_CALL_6(nr, sym) case nr: return __waml_##sym(arg1, arg2, arg3, arg4, arg5, arg6);
long __kernel_syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6)
{
switch (number) {
#include <wasmux/syscall-list.h>
}
return -ENOSYS;
}
#undef __SYSCALL_CALL_6
#define __SYSCALL_CALL_6(nr, sym)
