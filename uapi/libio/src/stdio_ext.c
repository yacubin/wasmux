/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdio_ext.h>
#include <assert.h>
#include <errno.h>

size_t __fpending(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return 0;
}

int __freading(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int __fwriting (FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void __fpurge(FILE* file)
{
  assert(0);
}

size_t __freadahead(FILE* file)
{
  assert(0);
  return 0;
}

const char* __freadptr(FILE* file, size_t* psize)
{
  assert(0);
  return NULL;
}

void __freadptrinc(FILE* file, size_t increment)
{
  assert(0);
}

void __fseterr(FILE* file)
{
  assert(0);
}
