/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <execinfo.h>
#include <stdlib.h>

int backtrace(void** arr, int size)
{
  abort();
  return -1;
}

char** backtrace_symbols(void* const* arr, int size)
{
  abort();
  return nullptr;
}

void backtrace_symbols_fd(void* const* arr, int size, int fd)
{
  abort();
}
