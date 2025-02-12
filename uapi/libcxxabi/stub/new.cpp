/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/types.h>
#include <wasmux/compiler.h>
#include <wasmux/assert.h>

__ATTR_HIDDEN
void* operator new(size_t size)
{
  WA_UNREACHABLE();
  return nullptr;
} 

__ATTR_HIDDEN
void operator delete(void* ptr) noexcept
{
  WA_UNREACHABLE();
}

__ATTR_HIDDEN
void* operator new[](size_t size)
{
  WA_UNREACHABLE();
  return nullptr;
} 

__ATTR_HIDDEN
void operator delete[](void* ptr) noexcept
{
  WA_UNREACHABLE();
}
