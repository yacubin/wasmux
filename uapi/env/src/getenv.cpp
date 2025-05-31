/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <stdlib.h>

char* getenv(const char* name)
{
#ifndef WASMUX_ENV_STUB
  abort();
#endif

  return nullptr;
}
