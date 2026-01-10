/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/errno.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

typedef long (syscall_fn) (long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

__EXPORT __ATTR_HIDDEN
long __waml_sys_ni_syscall(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6)
{
  return -ENOSYS;
}

#undef __SYSCALL
#define __SYSCALL(nr, argc, sym) __EXPORT long __waml_##sym(long, long, long, long, long, long);
#include <wasmux/syscall-list.h>

#define SYSCALL_STUB_DECL(sym) __EXPORT __ATTR_WEAK_ALIAS(__waml_sys_ni_syscall, __waml_##sym);
#define SYSCALL_STUB_DECL_0(sym) SYSCALL_STUB_DECL(sym)
#define SYSCALL_STUB_DECL_1(sym) SYSCALL_STUB_DECL(sym)
#define SYSCALL_STUB_DECL_2(sym) SYSCALL_STUB_DECL(sym)
#define SYSCALL_STUB_DECL_3(sym) SYSCALL_STUB_DECL(sym)
#define SYSCALL_STUB_DECL_4(sym) SYSCALL_STUB_DECL(sym)
#define SYSCALL_STUB_DECL_5(sym) SYSCALL_STUB_DECL(sym)
#define SYSCALL_STUB_DECL_6(sym) SYSCALL_STUB_DECL(sym)
#define SYSCALL_STUB_DECL_x(sym)

#undef __SYSCALL
#define __SYSCALL(nr, argc, sym) SYSCALL_STUB_DECL_##argc(sym)
#include <wasmux/syscall-list.h>

#undef __SYSCALL
#define __SYSCALL(nr, argc, sym) __waml_##sym,

static syscall_fn* sys_call_table[] = {
#include <wasmux/syscall-list.h>
};

long __kernel_syscall(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6)
{
  syscall_fn* fn = (number < sizeof(sys_call_table) / sizeof(*sys_call_table)) ? sys_call_table[number] : __waml_sys_ni_syscall;
  return fn(arg1, arg2, arg3, arg4, arg5, arg6);
}
