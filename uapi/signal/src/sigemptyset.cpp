/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <signal.h>
#include <errno.h>
#include <wasmux/assert.h>

int sigemptyset(sigset_t* set)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
