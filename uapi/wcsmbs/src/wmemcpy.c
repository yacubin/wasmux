/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wchar.h>

wchar_t* wmemcpy(wchar_t* wcs1, const wchar_t* wcs2, size_t len)
{
  return (wchar_t*)__builtin_memcpy(wcs1, wcs2, len * sizeof(*wcs2));
}
