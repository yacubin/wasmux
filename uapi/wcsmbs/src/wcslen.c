/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wchar.h>

size_t wcslen(const wchar_t* wcs)
{
  const wchar_t* ptr = wcs;
  while (*ptr)
    ptr++;
  return ptr - wcs;
}
