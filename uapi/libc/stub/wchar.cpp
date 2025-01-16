/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "wchar.h"

#include <wasmux/assert.h>
#include <waf/Characters.h>

int iswalnum(wint_t wc)
{
  WA_UNREACHABLE();
  return 0;
}

int iswprint(wint_t wc)
{
  WA_UNREACHABLE();
  return 0;
}

int iswspace(wint_t wc)
{
  WA_UNREACHABLE();
  return 0;
}

wint_t towlower(wint_t wc)
{
  WA_UNREACHABLE();
  return 0;
}

wint_t towupper(wint_t wc)
{
  WA_UNREACHABLE();
  return 0;
}

int wcwidth(wchar_t wc)
{
  WA_UNREACHABLE();
  return 0;
}

int wcswidth(const wchar_t* wcs, size_t len)
{
  WA_UNREACHABLE();
  return 0;
}

int wcscoll(const wchar_t* wcs1, const wchar_t* wcs2)
{
  WA_UNREACHABLE();
  return 0;
}

wint_t putwc(wchar_t wc, FILE* stream)
{
  WA_UNREACHABLE();
  return -1;
}
