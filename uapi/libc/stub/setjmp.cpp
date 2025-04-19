/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <setjmp.h>
#include <stdlib.h>
#include <errno.h>

int _setjmp(jmp_buf env)
{
  abort();
  errno = ENOSYS;
  return -1;
}

void _longjmp(jmp_buf env, int val)
{
  abort();
}

int setjmp(jmp_buf env)
{
  abort();
  errno = ENOSYS;
  return -1;
}

void longjmp(jmp_buf env, int val)
{
  abort();
}

void siglongjmp(sigjmp_buf env, int val)
{
  abort();
}

int sigsetjmp(sigjmp_buf env, int savesigs)
{
  return 0;
}
