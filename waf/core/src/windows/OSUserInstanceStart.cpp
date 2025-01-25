/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"


#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_UserInstanceStart(WEI_Object module, WEI_Object memory)
{
  return -1;
}

#endif
