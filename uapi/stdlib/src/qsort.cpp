/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <stdlib.h>
#include <wasmux/assert.h>

void qsort(void* base, size_t n, size_t size, int (*compare) (const void*, const void*))
{
  WA_UNREACHABLE();
}

void qsort_r(void* base, size_t n, size_t size, int (*compare) (const void*, const void*, void*), void* arg)
{
  WA_UNREACHABLE();
}
