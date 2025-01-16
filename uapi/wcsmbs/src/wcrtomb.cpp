/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wchar.h>
#include <wasmux/assert.h>

size_t wcrtomb(char* str, wchar_t wcs, mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}
