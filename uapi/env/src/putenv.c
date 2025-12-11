/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <stdlib.h>

int putenv(char* name)
{
#ifndef WASMUX_ENV_STUB
  abort();
#endif

  return -1;
}
