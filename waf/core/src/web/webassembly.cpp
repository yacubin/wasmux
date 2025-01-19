/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/web/webassembly.h>
#include <wasmux/web/object.h>

WEI_Object WebAssembly_compile(WEI_Object buffer)
{
  WEI_Object assembly = WebObject_getProperty(WEI_GLOBAL_THIS, "WebAssembly");
  WEI_Object promise = WebObject_callObjMethod(assembly, "compile", buffer, 0, 0, 0);
  WEI_objectRelease(assembly);
  return promise;
}
