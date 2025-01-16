/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wchar.h>
#include <string.h>

wchar_t* wmemcpy(wchar_t* wcs1, const wchar_t* wcs2, size_t len)
{
  return reinterpret_cast<wchar_t*>(memcpy(wcs1, wcs2, len * sizeof(*wcs2)));
}
