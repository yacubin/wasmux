/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdlib.h"
#include "unistd.h"

#include <wasmux/assert.h>

int atexit(void (*function)(void))
{
  WA_UNREACHABLE();
  return -1;
}

void exit(int status)
{
  WA_UNREACHABLE();
}

void _exit(int status)
{
  WA_UNREACHABLE();
}
