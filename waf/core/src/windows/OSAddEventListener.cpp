/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_AddEventListener(WEI_Object thisObject, WEI_Object type, WEI_PerformCallback1* callback, void* userdata)
{
  return -1;
}

#endif
