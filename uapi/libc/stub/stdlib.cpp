/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdlib.h"

#include <wasmux/assert.h>
#include <errno.h>

int system(const char* command)
{
  WA_UNREACHABLE();
  return -1;
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
