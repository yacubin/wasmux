/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <kernel/types.h>

namespace WAF {
enum CtorOnlyTag {CtorOnly};
}  // namespace WAF

inline void* operator new(size_t size, WAF::CtorOnlyTag, void* ptr)
{
  return ptr;
}
