/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_SetObjectProperty(WEI_Object object, WEI_Object name, WEI_Object value)
{
  return -1;
}
extern "C" int os_SetIntegerProperty(WEI_Object object, WEI_Object name, int value)
{
  return -1;
}

#endif
