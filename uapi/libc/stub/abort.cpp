/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdlib.h"

#include <wasmux/assert.h>

void abort(void)
{
  WA_UNREACHABLE();
}
