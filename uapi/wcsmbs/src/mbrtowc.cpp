/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wchar.h>
#include <wasmux/assert.h>

size_t mbrtowc(wchar_t* wcs, const char* str, size_t len, mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}
