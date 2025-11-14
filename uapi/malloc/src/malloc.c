/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <errno.h>
#include <assert.h>

void* malloc(size_t size)
{
  assert(0);
  return NULL;
}

void* calloc(size_t num, size_t size)
{
  assert(0);
  return NULL;
}

void* realloc(void* ptr, size_t size)
{
  assert(0);
  return NULL;
}

void free(void* ptr)
{
  assert(0);
}

void* aligned_alloc(size_t alignment, size_t size)
{
  assert(0);
  return NULL;
}

int posix_memalign(void** mem, size_t alignment, size_t size)
{
  assert(0);
  return ENOMEM;
}
