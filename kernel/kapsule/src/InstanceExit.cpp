/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

#ifdef __MINGW32__
__EXPORT int atexit(void (*__func) (void))
{
  return 0;
}
#else
__EXPORT __ATTR_HIDDEN
int __cxa_atexit(void (*destructor) (void* ptr), void* ptr, void* dso_handle)
{
  // TODO: Add distructor to array
  //       (-1) if could not add function
  //       lock/unlock

  return 0;
}
#endif
