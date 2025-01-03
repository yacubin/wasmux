/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "wchar.h"

#include <kernel/assert.h>
#include <waf/Characters.h>

int wctob(wint_t c)
{
  WA_UNREACHABLE();
  return 0;
}

wint_t btowc(int wc)
{
  WA_UNREACHABLE();
  return 0;
}

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

int mbsinit(const mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}

size_t mbrtowc(wchar_t* wcs, const char* str, size_t len, mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}

size_t wcrtomb(char* str, wchar_t wcs, mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}

size_t mbrlen(const char* str, size_t len, mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}

size_t mbsrtowcs(wchar_t* dst, const char** src, size_t dstlen, mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}

size_t wcsrtombs(char* dst, const wchar_t** src, size_t dstlen, mbstate_t* state)
{
  WA_UNREACHABLE();
  return 0;
}

int wcscmp(const wchar_t* wcs1, const wchar_t* wcs2)
{
  return WAF::charactersCompare(wcs1, wcs2);
}

int wcsncmp(const wchar_t* wcs1, const wchar_t* wcs2, size_t len)
{
  WA_UNREACHABLE();
  return 0;
}

wchar_t* wmemcpy(wchar_t* wcs1, const wchar_t* wcs2, size_t len)
{
  WA_UNREACHABLE();
  return nullptr;
}

size_t wcslen(const wchar_t* wcs)
{
  return WAF::charactersLength(wcs);
}

wchar_t* wcscat(wchar_t* dst, const wchar_t* src)
{
  WA_UNREACHABLE();
  return nullptr;
}

int wcswidth(const wchar_t* wcs, size_t len)
{
  WA_UNREACHABLE();
  return 0;
}

wchar_t* wcschr(const wchar_t* wcs, wchar_t wch)
{
  WA_UNREACHABLE();
  return nullptr;
}

wchar_t* wmemchr(const wchar_t* wcs, wchar_t wch, size_t len)
{
  WA_UNREACHABLE();
  return nullptr;
}

wchar_t* wcscpy(wchar_t* dst, const wchar_t* src)
{
  return WAF::charactersCopy(dst, src);
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
