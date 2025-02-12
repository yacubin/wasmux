/*
 *
 *  Copyright (C) 2024-2025 Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_ObjectRelease(WEI_Object object)
{
  return -1;
}

#endif
