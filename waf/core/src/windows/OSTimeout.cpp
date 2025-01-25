/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" unsigned os_SetTimeout(WEI_PerformCallback* callback, void* userdata, int delayMs)
{
  return 0;
}

extern "C" unsigned os_SetInterval(WEI_PerformCallback* callback, void* userdata, int delayMs)
{
  return 0;
}

extern "C" void os_ClearTimeout(unsigned timeoutID)
{
}

extern "C" void os_ClearInterval(unsigned intervalID)
{
}

#endif
