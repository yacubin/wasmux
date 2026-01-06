/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wchar.h>

int wcsncmp(const wchar_t* wcs1, const wchar_t* wcs2, size_t len)
{
  wchar_t c1, c2;

  while (len != 0) {
    c1 = *wcs1;
    c2 = *wcs2;

    if (c1 != c2)
      return c1 < c2 ? -1 : 1;

    if (!c1)
      break;

    wcs1++;
    wcs2++;
    len--;
  }

  return 0;
}
