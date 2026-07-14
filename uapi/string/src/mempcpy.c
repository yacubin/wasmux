/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>

void* mempcpy(void* dst, const void* src, size_t n)
{
  __builtin_memcpy(dst, src, n);
  return ((char*)dst) + n;
}
