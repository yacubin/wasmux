/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <wasmux/assert.h>

void abort(void)
{
  while (1) {
    WA_UNREACHABLE();
  }
}
