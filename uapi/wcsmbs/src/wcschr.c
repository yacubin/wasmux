/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wchar.h>

wchar_t* wcschr(const wchar_t* wcs, wchar_t wch)
{
  for (;;) {
    wchar_t c = *wcs;
    if (c == '\0')
      break;
    if (c == wch)
      return wcs;
    wcs++;
  }
  return NULL;
}
