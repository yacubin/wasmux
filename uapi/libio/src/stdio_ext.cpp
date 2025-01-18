/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdio_ext.h"

#include <wasmux/assert.h>
#include <errno.h>

size_t __fpending(FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return 0;
}

int __freading(FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int __fwriting (FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

void __fpurge(FILE* file)
{
  WA_UNREACHABLE();
}

size_t __freadahead(FILE* file)
{
  WA_UNREACHABLE();
  return 0;
}

const char* __freadptr(FILE* file, size_t* psize)
{
  WA_UNREACHABLE();
  return nullptr;
}

void __freadptrinc(FILE* file, size_t increment)
{
  WA_UNREACHABLE();
}

void __fseterr(FILE* file)
{
  WA_UNREACHABLE();
}
