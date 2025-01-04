/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdlib.h"

#include <kernel/assert.h>
#include <errno.h>

int system(const char* command)
{
  WA_UNREACHABLE();
  return -1;
}

int abs(int i)
{
  WA_UNREACHABLE();
  return i;
}

void srand(unsigned seed)
{
  WA_UNREACHABLE();
}

int rand(void)
{
  WA_UNREACHABLE();
  return -1;
}

void srandom(unsigned seed)
{
  WA_UNREACHABLE();
}

long random(void)
{
  WA_UNREACHABLE();
  return -1;
}

char* initstate(unsigned seed, char* state, size_t n)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

char* setstate(char* state)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int wctomb(char* str, wchar_t wch)
{
  WA_UNREACHABLE();
  return -1;
}

int mkstemp(char* temp)
{
  WA_UNREACHABLE();
  return -1;
}

char* mktemp(char* pattern)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int mblen(const char* str, size_t len)
{
  WA_UNREACHABLE();
  return -1;
}

int mbtowc(wchar_t* pwc, const char* str, size_t len)
{
  WA_UNREACHABLE();
  return -1;
}

size_t mbstowcs(wchar_t* dst, const char* src, size_t dstlen)
{
  WA_UNREACHABLE();
  return 0;
}

size_t wcstombs(char* dst, const wchar_t* src, size_t dstlen)
{
  WA_UNREACHABLE();
  return 0;
}
