/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <stdlib.h>
#include <kernel/compiler.h>

void* malloc(size_t size)
{
  return nullptr;
}

void* calloc(size_t num, size_t size)
{
  return nullptr;
}

void* realloc(void* ptr, size_t size)
{
  return nullptr;
}

void free(void* ptr)
{
}
