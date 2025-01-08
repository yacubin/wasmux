/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/assert.h>

__attribute__((visibility("hidden")))
extern "C" void cxxabi_dummy()
{
  WA_UNREACHABLE();
}
