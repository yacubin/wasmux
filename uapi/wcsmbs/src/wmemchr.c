/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wchar.h>

wchar_t* wmemchr(const wchar_t* wcs, wchar_t wch, size_t len)
{
  for (; len != 0; len--, wcs++) {
    wchar_t c = *wcs;
    if (c == 0)
      break;
    if (c == wch)
      return wcs;
  }
  return NULL;
}
