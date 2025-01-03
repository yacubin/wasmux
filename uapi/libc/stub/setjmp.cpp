/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "setjmp.h"

#include <kernel/assert.h>
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
