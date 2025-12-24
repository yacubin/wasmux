/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <dlfcn.h>
#include <stddef.h> // for NULL
#include <assert.h>

void* dlopen(const char* filename, int flag)
{
  assert(0);
  return NULL;
}

char* dlerror(void)
{
  assert(0);
  return NULL;
}

void* dlsym(void* handle, const char* symbol)
{
  assert(0);
  return NULL;
}

int dlclose(void* handle)
{
  assert(0);
  return -1;
}

int dladdr(const void* addr, Dl_info* info)
{
  assert(0);
  return -1;
}
