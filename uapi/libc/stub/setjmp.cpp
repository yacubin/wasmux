/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <setjmp.h>
#include <wasmux/assert.h>
#include <errno.h>

int setjmp(jmp_buf env)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

void longjmp(jmp_buf env, int val)
{
  WA_UNREACHABLE();
}

void siglongjmp(sigjmp_buf env, int val)
{
  WA_UNREACHABLE();
}

int sigsetjmp(sigjmp_buf env, int savesigs)
{
  return 0;
}
