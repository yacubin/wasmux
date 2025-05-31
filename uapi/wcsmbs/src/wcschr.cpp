/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wchar.h>
#include <wasmux/cxx/Characters.h>

wchar_t* wcschr(const wchar_t* wcs, wchar_t wch)
{
  return const_cast<wchar_t*>(wasmux::charactersFind<wchar_t,true>(wcs, wch));
}
