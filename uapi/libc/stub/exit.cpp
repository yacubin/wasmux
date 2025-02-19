/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <stdlib.h>
#include <unistd.h>

#include <assert.h>

int atexit(void (*function)(void))
{
  assert(0);
  return -1;
}

void exit(int status)
{
  assert(0);
}
