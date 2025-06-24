/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/webassembly.h>
#include <wasmux/web/object.h>
#include <wasmux/cxx/ObjectCast.h>

WEI_Object WebAssembly_compile(WEI_Object buffer)
{
  WEI_Object assembly = WebObject_getProperty(WEI_GLOBAL_THIS, "WebAssembly");
  WEI_Object promise = WebObject_callObjMethod(assembly, "compile", buffer, 0, 0, 0);
  WEI_objectRelease(assembly);
  return promise;
}

WebAssemblyMemory* WebAssemblyMemory_create(unsigned initial, unsigned maximum, bool shared)
{
  WEI_Object assembly = WebObject_getProperty(WEI_GLOBAL_THIS, "WebAssembly");

  WEI_Object memoryDescriptor = WebObject_create();
  WebObject_setIntegerProperty(memoryDescriptor, "initial", initial);
  WebObject_setIntegerProperty(memoryDescriptor, "maximum", maximum);
  WebObject_setProperty(memoryDescriptor, "shared", shared ? WEI_TRUE_BOOLEAN_ID : WEI_FALSE_BOOLEAN_ID);

  WEI_Object memoryConstructor = WebObject_getProperty(assembly, "Memory");
  WEI_Object result = WEI_objectCreate1(memoryConstructor, memoryDescriptor);

  WEI_objectRelease(memoryDescriptor);
  WEI_objectRelease(memoryConstructor);
  WEI_objectRelease(assembly);

  return object_ptr_cast<WebAssemblyMemory>(result);
}

void WebAssemblyMemory_finalize(WebAssemblyMemory* thiz)
{
  WEI_objectRelease(object_idx_cast(thiz));
}
