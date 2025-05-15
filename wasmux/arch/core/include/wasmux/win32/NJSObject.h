/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/wei.h>

namespace WEI {

class NJSObject {
public:
  void ref() const
  {
    m_refCount++;
  }

  void unref()
  {
    unsigned temp = m_refCount - 1;
    if (!temp)
      destroy();
    else
      m_refCount = temp;
  }

  void destroy();

  bool isString() const { return m_classType == StringClass; }

protected:
  enum ClassType {
    StringClass,
  };

  NJSObject(ClassType classType);

private:
  mutable unsigned m_refCount;
  unsigned m_classType;
};

} // namespace WEI
