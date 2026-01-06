/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <stdlib.h>

int setenv(const char* name, const char* value, int overwrite)
{
#ifndef WASMUX_ENV_STUB
  abort();
#endif

  return -1;
}
