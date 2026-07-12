/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wchar.h>

wchar_t* wcsncpy(wchar_t* dst, const wchar_t* src, size_t n)
{
  for (size_t i = 0; i < n; i++) {
    wchar_t ch = dst[i] = src[i];
    if (ch == L'\0') {
      if (++i < n)
        __builtin_memset(&dst[i], 0, sizeof(wchar_t) * (n - i));
      break;
    }
  }
  return dst;
}
