/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" WEI_Object os_GetObjectProperty(WEI_Object object, WEI_Object name)
{
  return WEI_UNDEFINED_OBJECT;
}

extern "C" int os_GetIntegerProperty(WEI_Object object, WEI_Object name)
{
  return -1;
}

#endif
