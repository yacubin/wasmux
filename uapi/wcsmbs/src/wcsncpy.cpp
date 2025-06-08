/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <wchar.h>

wchar_t* wcsncpy(wchar_t* dst, const wchar_t* src, size_t n)
{
  return wasmux::charactersCopy(dst, src, n);
}
