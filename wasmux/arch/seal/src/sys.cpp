/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/assert.h>
#include <wasmux/errno.h>
#include <wasmux/arch/syscall-define.h>

SYSCALL_DEFINE3(fcntl64, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE3(waitpid, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE3(open, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE1(close, long, a1) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE3(write, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE2(dup2, long, a1, long, a2) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE1(exit_group, long, a1) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE1(exit, long, a1) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE1(chdir, long, a1) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE2(getcwd, long, a1, long, a2) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE0(getuid)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE5(statx, long, a1, long, a2, long, a3, long, a4, long, a5) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE4(openat, long, a1, long, a2, long, a3, long, a4) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE0(geteuid) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE0(getgid) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE0(getpid) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE2(gettimeofday, long, a1, long, a2) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE3(ioctl, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE5(llseek, long, a1, long, a2, long, a3, long, a4, long, a5) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE3(mknod, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE1(newuname, long, a1) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}
