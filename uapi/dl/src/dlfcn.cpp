/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "dlfcn.h"

#include <kernel/assert.h>

void* dlopen(const char* filename, int flag)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* dlerror(void)
{
  WA_UNREACHABLE();
  return nullptr;
}

void* dlsym(void* handle, const char* symbol)
{
  WA_UNREACHABLE();
  return nullptr;
}

int dlclose(void* handle)
{
  WA_UNREACHABLE();
  return -1;
}

int dladdr(const void* addr, Dl_info* info)
{
  WA_UNREACHABLE();
  return -1;
}
