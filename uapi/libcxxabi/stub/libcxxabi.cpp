/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/assert.h>

__attribute__((visibility("hidden")))
extern "C" void cxxabi_dummy()
{
  WA_UNREACHABLE();
}
