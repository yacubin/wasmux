/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/cxx/RefPtr.h>
#include "NJSObject.h"

namespace WEI {

class NJSString : public NJSObject {
public:
  static RefPtr<NJSString> create(const char* characters, unsigned length);
  const char* characters() const { return m_characters; }
  unsigned length() const { return m_length; }

private:
  NJSString(const char* characters, unsigned length);

  unsigned m_length;
  char m_characters[1];
};

} // namespace WEI
