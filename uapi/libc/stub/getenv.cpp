/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdlib.h"

#include <wasmux/assert.h>

char* getenv(const char* name)
{
  WA_UNREACHABLE();
  return nullptr;
}

int setenv(const char* name, const char* value, int overwrite)
{
  WA_UNREACHABLE();
  return -1;
}

int putenv(char* name)
{
  WA_UNREACHABLE();
  return -1;
}

int unsetenv(const char* name)
{
  WA_UNREACHABLE();
  return -1;
}
