/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <obstack.h>
#include <wasmux/compiler.h>
#include <wasmux/assert.h>

void _obstack_free(struct obstack* obstack, void* obj)
{
  WA_UNREACHABLE();
}
