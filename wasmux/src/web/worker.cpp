/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/worker.h>
#include <wasmux/web/object.h>
#include <wasmux/wei.h>

WebWorker* WebWorker_create(const WebString* url, const WebString* name)
{
  // WEI_Object clsObj = WebObject_getProperty(WEI_GLOBAL_THIS, "Worker");
  WEI_Object optionsObj = WebObject_create();
  WebObject_setProperty(optionsObj, "name", wobject_idx(name));
  WEI_Object result = WEI_objectCreate2(WEI_WORKER_CTOR_ID, wobject_idx(url), optionsObj);
  WEI_objectRelease(optionsObj);
  // WEI_objectRelease(clsObj);
  return wobject_ptr(WebWorker, result);
}

WebWorker* WebWorker_create2(const char* url, const char* name)
{
  WebString* urlObj = WebString_create(url);
  WebString* nameObj = WebString_create(name);
  WebWorker* result = WebWorker_create(urlObj, nameObj);
  WebString_destroy(nameObj);
  WebString_destroy(urlObj);
  return  result;
}

int WebWorker_terminate(WebWorker* thiz)
{
  WebString* terminate = WebString_create("terminate");
  int result = WEI_callIntegerMethod(wobject_idx(thiz), wobject_idx(terminate));
  WebString_destroy(terminate);
  return result;
}
