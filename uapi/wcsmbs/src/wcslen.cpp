/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wchar.h>
#include <waf/Characters.h>
#include <wasmux/assert.h>

size_t wcslen(const wchar_t* wcs)
{
  return WAF::charactersLength(wcs);
}
