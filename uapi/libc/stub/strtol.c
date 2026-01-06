/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <assert.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

long strtol(const char* str, char** endstr, int base)
{
  assert(0);
  return 0;
}

long long strtoll(const char* str, char** end, int base)
{
  assert(0);
  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(strtoll, strtoimax);

unsigned long strtoul(const char* str, char** end, int base)
{
  assert(0);
  return 0ul;
}

unsigned long long strtoull(const char* str, char** end, int base)
{
  assert(0);
  return 0ull;
}

__EXPORT __ATTR_WEAK_ALIAS(strtoull, strtoumax);

float strtof(const char* str, char** end)
{
  assert(0);
  return 0.0f;
}

double strtod(const char* str, char** endstr)
{
  assert(0);
  return 0.0;
}

int atoi(const char* str)
{
  assert(0);
  return 0;
}

long atol(const char* str)
{
  assert(0);
  return 0l;
}

long long atoll(const char* str)
{
  return 0ll;
}

double atof(const char* str)
{
  assert(0);
  return 0.0;
}
