/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <wchar.h>

wchar_t* wmemchr(const wchar_t* wcs, wchar_t wch, size_t len)
{
  return const_cast<wchar_t*>(wasmux::charactersFind<wchar_t,true>(wcs, wch, len));
}
