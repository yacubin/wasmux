/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <string.h>

void* memcpy(void* dst, const void* src, size_t n)
{
  return __builtin_memcpy(dst, src, n);
}

void* mempcpy(void* dst, const void* src, size_t n)
{
  __builtin_memcpy(dst, src, n);
  return reinterpret_cast<char*>(dst) + n;
}
