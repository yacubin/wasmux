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

SYSCALL_DEFINE3(fcntl64, long, a1, long, a2, long, a3) __ATTR_WEAK
{
  WA_UNREACHABLE();
  return -ENOSYS;
}

#endif /* __ARCH_WANT_SYSCALL_DEFINES */
