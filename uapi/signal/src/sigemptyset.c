/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <signal.h>
#include <errno.h>
#include <assert.h>

int sigemptyset(sigset_t* set)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
