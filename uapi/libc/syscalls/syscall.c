/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

#ifdef ARCH_HAS_UAPI_SYSCALL

long syscall(long number, ...)
{
  long a1, a2, a3, a4, a5, a6;

  va_list args;
  va_start(args, number);
  a1 = va_arg(args, long);
  a2 = va_arg(args, long);
  a3 = va_arg(args, long);
  a4 = va_arg(args, long);
  a5 = va_arg(args, long);
  a6 = va_arg(args, long);
  va_end(args);

  long ret = __SYSCALL(number, a1, a2, a3, a4, a5, a6);
  if ((unsigned long)ret > -4096UL) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return ret;
}

#endif
