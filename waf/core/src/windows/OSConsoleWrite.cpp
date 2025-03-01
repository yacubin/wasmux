/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

#include <windows.h>

#include "NJSString.h"
#include "BaseThreadContext.h"

extern "C" int os_ConsoleWrite(int level, WEI_Object message)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  RefPtr<WEI::NJSString> string = reinterpret_cast<WEI::NJSString*>(WEI::BaseThreadContext::getInstance().objects().get(message));
  DWORD dataWritten1, dataWritten2;
  WriteConsole(hConsole, string->characters(), string->length(), &dataWritten1, nullptr);
  WriteConsole(hConsole, "\n", 1, &dataWritten2, nullptr);
  return static_cast<int>(dataWritten1 + dataWritten2);
}

#endif
