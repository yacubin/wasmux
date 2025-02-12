/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wchar.h>
#include <wasmux/cxx/Characters.h>

wchar_t* wcscpy(wchar_t* dst, const wchar_t* src)
{
  return WAF::charactersCopy(dst, src);
}
