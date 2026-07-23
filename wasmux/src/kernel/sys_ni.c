/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/errno.h>

long sys_ni_syscall0()
{
  return -ENOSYS;
}

long sys_ni_syscall1(long arg1)
{
  return -ENOSYS;
}

long sys_ni_syscall2(long arg1, long arg2)
{
  return -ENOSYS;
}

long sys_ni_syscall3(long arg1, long arg2, long arg3)
{
  return -ENOSYS;
}

long sys_ni_syscall4(long arg1, long arg2, long arg3, long arg4)
{
  return -ENOSYS;
}

long sys_ni_syscall5(long arg1, long arg2, long arg3, long arg4, long arg5)
{
  return -ENOSYS;
}

long sys_ni_syscall6(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6)
{
  return -ENOSYS;
}
