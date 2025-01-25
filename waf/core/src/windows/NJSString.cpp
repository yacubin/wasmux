/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include "NJSString.h"

#include <wasmux/bulk-memory.h>
#include <wasmux/cxx/New.h>

#include "OSMalloc.h"

namespace WEI {

NJSString::NJSString(const char* characters, unsigned length)
  : NJSObject(StringClass)
  , m_length(length)
{
  kernel_memory_copy(m_characters, characters, length);
  m_characters[length] = '\0';
}

RefPtr<NJSString> NJSString::create(const char* characters, unsigned length)
{
  void* ptr = OSMalloc(sizeof(NJSString) + length);
  if (ptr == nullptr)
    return {};
  return newRef(new (WAF::CtorOnly, ptr) NJSString(characters, length));
}

} // namespace WEI
