/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wchar.h>

wchar_t* wcscpy(wchar_t* dst, const wchar_t* src)
{
  wchar_t* ret = dst;
  for (;;) {
    wchar_t ch = *dst = *src;
    if (ch == '\0')
      break;
    src++;
    dst++;
  }

  return ret;
}
