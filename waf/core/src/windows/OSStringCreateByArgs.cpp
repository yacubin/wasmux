/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/platform.h>
#include <wasmux/wei.h>

#include "NJSString.h"
#include "BaseThreadContext.h"

#ifdef WA_OS_WINDOWS

extern "C" int os_StringCreateByArgs(unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4, unsigned arg5, unsigned arg6)
{
  constexpr auto N = WEI_WEBCALL_NARGS * sizeof(unsigned);

  char buffer[N];

  uint8_t length = arg1;
  if (length >= N) {
    return -1; // Error: Invalid argument
  }

  buffer[0] = arg1 >> 8;
  buffer[1] = arg1 >> 16;
  buffer[2] = arg1 >> 24;

  buffer[3] = arg2 >> 0;
  buffer[4] = arg2 >> 8;
  buffer[5] = arg2 >> 16;
  buffer[6] = arg2 >> 24;

  buffer[7] = arg3 >> 0;
  buffer[8] = arg3 >> 8;
  buffer[9] = arg3 >> 16;
  buffer[10] = arg3 >> 24;

  buffer[11] = arg4 >> 0;
  buffer[12] = arg4 >> 8;
  buffer[13] = arg4 >> 16;
  buffer[14] = arg4 >> 24;

  buffer[15] = arg5 >> 0;
  buffer[16] = arg5 >> 8;
  buffer[17] = arg5 >> 16;
  buffer[18] = arg5 >> 24;

  buffer[19] = arg6 >> 0;
  buffer[20] = arg6 >> 8;
  buffer[21] = arg6 >> 16;
  buffer[22] = arg6 >> 24;

  auto string = WEI::NJSString::create(buffer, length);
  return WEI::BaseThreadContext::getInstance().objects().add(string);
}

#endif
