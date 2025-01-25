/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include "NJSObject.h"
#include "OSMalloc.h"
#include "NJSString.h"

namespace WEI {

NJSObject::NJSObject(ClassType classType)
  : m_refCount(1)
  , m_classType(classType)
{
}

void NJSObject::destroy()
{
  switch (m_classType) {
  case StringClass:
    reinterpret_cast<NJSString*>(this)->~NJSString();
    break;
  }

  OSFree(this);
}

} // namespace WEI
