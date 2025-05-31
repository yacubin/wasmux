/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <wchar.h>

int wcscmp(const wchar_t* wcs1, const wchar_t* wcs2)
{
  return wasmux::charactersCompare(wcs1, wcs2);
}
