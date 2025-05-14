/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/errno.h>
#include <wasmux/arch/syscall-define.h>

SYSCALL_DEFINE1(brk, long, a1) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE3(fcntl64, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE3(waitpid, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE3(open, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE1(close, long, a1) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE3(write, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE2(dup2, long, a1, long, a2) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE1(exit_group, long, a1) __ATTR_WEAK
{
  return -ENOSYS;
}

SYSCALL_DEFINE1(exit, long, a1) __ATTR_WEAK
{
  return -ENOSYS;
}
