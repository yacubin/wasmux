/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/wei.h>
#include <wasmux/assert.h>
#include <wasmux/limits-base.h>

namespace wasmux {

template<typename T>
inline WEI_Object object_idx_cast(T* ptr)
{
  WA_ASSERT(reinterpret_cast<unsigned long>(ptr) <= UINT_MAX);
  return static_cast<WEI_Object>(reinterpret_cast<unsigned long>(ptr));
}

template<typename T>
inline T* object_ptr_cast(WEI_Object object)
{
  return reinterpret_cast<T*>(object);
}

} // namespace wasmux

using namespace wasmux;
