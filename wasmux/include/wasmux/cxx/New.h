/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>

namespace wasmux {

enum CtorOnlyTag {CtorOnly};

} // namespace wasmux

inline void* operator new(size_t size, wasmux::CtorOnlyTag, void* ptr)
{
  return ptr;
}
