/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wchar.h>
#include <wasmux/assert.h>
#include <wasmux/cxx/Characters.h>

size_t wcslen(const wchar_t* wcs)
{
  return WAF::charactersLength(wcs);
}
