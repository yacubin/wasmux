/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux/types.h>
#include <wasmux/compiler.h>
#include <wasmux/assert.h>

#ifdef __MINGW32__
__ATTR_HIDDEN
int atexit(void (*__func) (void))
{
  WA_UNREACHABLE();
  return 0;
}
#else
__ATTR_HIDDEN
int __cxa_atexit(void (*destructor) (void* ptr), void* ptr, void* dso_handle)
{
  WA_UNREACHABLE();
  return 0;
}
#endif
