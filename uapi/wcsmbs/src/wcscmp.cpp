/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wchar.h>
#include <wasmux/cxx/Characters.h>

int wcscmp(const wchar_t* wcs1, const wchar_t* wcs2)
{
  return WAF::charactersCompare(wcs1, wcs2);
}
