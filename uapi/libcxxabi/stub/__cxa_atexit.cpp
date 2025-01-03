/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/types.h>
#include <kernel/compiler.h>
#include <kernel/assert.h>

#ifdef __MINGW32__
__ATTR_HIDDEN
extern "C" int atexit(void (*__func) (void))
{
  WA_UNREACHABLE();
  return 0;
}
#else
__ATTR_HIDDEN
extern "C" int __cxa_atexit(void (*destructor) (void* ptr), void* ptr, void* dso_handle)
{
  WA_UNREACHABLE();
  return 0;
}
#endif
