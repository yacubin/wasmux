/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>

size_t strnlen(const char* str, size_t len)
{
  size_t n = 0;
  while (n < len && str[n])
    n++;
  return n;
}
