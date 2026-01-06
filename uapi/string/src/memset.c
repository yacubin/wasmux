/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>

void* memset(void* mem, int ch, size_t n)
{
  return __builtin_memset(mem, ch, n);
}
