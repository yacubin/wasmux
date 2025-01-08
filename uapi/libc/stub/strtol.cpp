/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdlib.h"

#include <wasmux/assert.h>
#include <wasmux/compiler.h>

long strtol(const char* str, char** endstr, int base)
{
  WA_UNREACHABLE();
  return 0;
}

long long strtoll(const char* str, char** end, int base)
{
  WA_UNREACHABLE();
  return 0;
}

extern "C" __ATTR_ALIAS(strtoll, strtoimax) __ATTR_WEAK;

unsigned long strtoul(const char* str, char** end, int base)
{
  WA_UNREACHABLE();
  return 0UL;
}

unsigned long long strtoull(const char* str, char** end, int base)
{
  WA_UNREACHABLE();
  return 0ULL;
}

extern "C" __ATTR_ALIAS(strtoull, strtoumax) __ATTR_WEAK;

float strtof(const char* str, char** end)
{
  WA_UNREACHABLE();
  return 0.0f;
}

double strtod(const char* str, char** endstr)
{
  WA_UNREACHABLE();
  return 0;
}

int atoi(const char* str)
{
  WA_UNREACHABLE();
  return 0;
}

long atol(const char* str)
{
  WA_UNREACHABLE();
  return 0;
}

double atof(const char* str)
{
  WA_UNREACHABLE();
  return 0.0;
}
