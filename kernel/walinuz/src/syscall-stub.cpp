/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/errno.h>

__ATTR_HIDDEN
extern "C" long sys_ni_syscall0()
{
  return -ENOSYS;
}

__ATTR_HIDDEN
extern "C" long sys_ni_syscall1(long arg1)
{
  return -ENOSYS;
}

__ATTR_HIDDEN
extern "C" long sys_ni_syscall2(long arg1, long arg2)
{
  return -ENOSYS;
}

__ATTR_HIDDEN
extern "C" long sys_ni_syscall3(long arg1, long arg2, long arg3)
{
  return -ENOSYS;
}

__ATTR_HIDDEN
extern "C" long sys_ni_syscall4(long arg1, long arg2, long arg3, long arg4)
{
  return -ENOSYS;
}

__ATTR_HIDDEN
extern "C" long sys_ni_syscall5(long arg1, long arg2, long arg3, long arg4, long arg5)
{
  return -ENOSYS;
}

__ATTR_HIDDEN
extern "C" long sys_ni_syscall6(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6)
{
  return -ENOSYS;
}

#define __SYSCALL_DECL_x(sym)
#define __SYSCALL_DECL_0(sym) extern "C" __ATTR_ALIAS(sys_ni_syscall0, __waml_##sym) __ATTR_WEAK;
#define __SYSCALL_DECL_1(sym) extern "C" __ATTR_ALIAS(sys_ni_syscall1, __waml_##sym) __ATTR_WEAK;
#define __SYSCALL_DECL_2(sym) extern "C" __ATTR_ALIAS(sys_ni_syscall2, __waml_##sym) __ATTR_WEAK;
#define __SYSCALL_DECL_3(sym) extern "C" __ATTR_ALIAS(sys_ni_syscall3, __waml_##sym) __ATTR_WEAK;
#define __SYSCALL_DECL_4(sym) extern "C" __ATTR_ALIAS(sys_ni_syscall4, __waml_##sym) __ATTR_WEAK;
#define __SYSCALL_DECL_5(sym) extern "C" __ATTR_ALIAS(sys_ni_syscall5, __waml_##sym) __ATTR_WEAK;
#define __SYSCALL_DECL_6(sym) extern "C" __ATTR_ALIAS(sys_ni_syscall6, __waml_##sym) __ATTR_WEAK;

#define __SYSCALL(nr, argc, sym) __SYSCALL_DECL_##argc(sym)
#include <wasmux/syscall-list.h>
