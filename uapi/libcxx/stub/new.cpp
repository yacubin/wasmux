/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/types.h>
#include <kernel/compiler.h>
#include <kernel/assert.h>

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
