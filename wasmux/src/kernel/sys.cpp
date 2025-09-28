/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>
#include <wasmux/assert.h>
#include <wasmux/errno.h>

#ifdef __ARCH_WANT_SYSCALL_DEFINES

WEAK_SYSCALL_DEFINE3(waitpid, long, a1, long, a2, long, a3)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

SYSCALL_DEFINE3(open, long, a1, long, a2, long, a3)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE1(close, long, a1)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE3(write, long, a1, long, a2, long, a3)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE2(dup2, long, a1, long, a2)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE1(exit_group, long, a1)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE1(exit, long, a1)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE1(chdir, long, a1)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE2(getcwd, long, a1, long, a2)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE0(getuid)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE5(statx, long, a1, long, a2, long, a3, long, a4, long, a5)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE4(openat, long, a1, long, a2, long, a3, long, a4)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE0(geteuid)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE0(getgid)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE0(getpid)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE2(gettimeofday, long, a1, long, a2)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE3(ioctl, long, a1, long, a2, long, a3)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE5(llseek, long, a1, long, a2, long, a3, long, a4, long, a5)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE3(mknod, long, a1, long, a2, long, a3)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

WEAK_SYSCALL_DEFINE1(newuname, long, a1)
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

#endif /* __ARCH_WANT_SYSCALL_DEFINES */
