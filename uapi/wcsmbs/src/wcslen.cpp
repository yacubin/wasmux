/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <wchar.h>

size_t wcslen(const wchar_t* wcs)
{
  return wasmux::charactersLength(wcs);
}
