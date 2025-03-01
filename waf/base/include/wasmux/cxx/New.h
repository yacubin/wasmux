/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>

namespace WAF {
enum CtorOnlyTag {CtorOnly};
}  // namespace WAF

inline void* operator new(size_t size, WAF::CtorOnlyTag, void* ptr)
{
  return ptr;
}
