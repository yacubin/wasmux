/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <stdlib.h>
#include <wasmux/compiler.h>
#include <wasmux/assert.h>

void* malloc(size_t size)
{
  WA_UNREACHABLE();
  return nullptr;
}

void* calloc(size_t num, size_t size)
{
  WA_UNREACHABLE();
  return nullptr;
}

void* realloc(void* ptr, size_t size)
{
  WA_UNREACHABLE();
  return nullptr;
}

void free(void* ptr)
{
  WA_UNREACHABLE();
}

void* aligned_alloc(size_t alignment, size_t size)
{
  WA_UNREACHABLE();
  return nullptr;
}