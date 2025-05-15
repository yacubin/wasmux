/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#define __SSIZE_T__ int // For windows.h

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

#include <wasmux/win32/NJSString.h>
#include <wasmux/win32/BaseThreadContext.h>

extern "C" int os_StringCreate(WEI_Object memory, const char* str, unsigned len)
{
  auto string = WEI::NJSString::create(str, len);
  return WEI::BaseThreadContext::getInstance().objects().add(string);
}

#endif
