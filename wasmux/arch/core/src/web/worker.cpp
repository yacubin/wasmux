/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/worker.h>
#include <wasmux/web/string.h>

WEI_Object WebWorker_create(WEI_Object url, WEI_Object name)
{
  WEI_Object clsObj = WebObject_getProperty(WEI_GLOBAL_THIS, "Worker");
  WEI_Object optionsObj = WebObject_create();
  WebObject_setProperty(optionsObj, "name", name);
  WEI_Object result = WEI_objectCreate2(clsObj, url, optionsObj);
  WEI_objectRelease(optionsObj);
  WEI_objectRelease(clsObj);
  return result;
}

WEI_Object WebWorker_create2(const char* url, const char* name)
{
  WebString* urlObj = WebString_create(url);
  WebString* nameObj = WebString_create(name);
  WEI_Object result = WebWorker_create(wobject_idx(urlObj), wobject_idx(nameObj));
  WebString_destroy(nameObj);
  WebString_destroy(urlObj);
  return result;
}

int WebWorker_terminate(WEI_Object worker)
{
  WebString* terminate = WebString_create("terminate");
  int result = WEI_callIntegerMethod(worker, wobject_idx(terminate));
  WebString_destroy(terminate);
  return result;
}
