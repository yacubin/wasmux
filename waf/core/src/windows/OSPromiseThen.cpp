/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_PromiseThen(WEI_Object thisObject, WEI_PerformCallback1* resolveCallback, WEI_PerformCallback1* rejectCallback, void* userdata)
{
  return -1;
}

#endif
