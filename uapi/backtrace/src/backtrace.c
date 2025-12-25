/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <execinfo.h>
#include <stdlib.h>
#include <assert.h>

int backtrace(void** arr, int size)
{
  assert(0);
  return -1;
}

char** backtrace_symbols(void* const* arr, int size)
{
  assert(0);
  return NULL;
}

void backtrace_symbols_fd(void* const* arr, int size, int fd)
{
  assert(0);
}
