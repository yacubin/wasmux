/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/xmlhttprequest.h>
#include <wasmux/assert.h>
#include <wasmux/web/string.h>

const char* WebXMLHttpRequest_ReadyState_toCString(WebXMLHttpRequest_ReadyState readyState)
{
  switch (readyState) {
  case WebXMLHttpRequest_ReadyState_UNSENT:
    return "UNSENT";
  case WebXMLHttpRequest_ReadyState_OPENED:
    return "OPENED";
  case WebXMLHttpRequest_ReadyState_HEADERS_RECEIVED:
    return "HEADERS_RECEIVED";
  case WebXMLHttpRequest_ReadyState_LOADING:
    return "LOADING";
  case WebXMLHttpRequest_ReadyState_DONE:
    return "DONE";
  }
  WA_UNREACHABLE();
  return nullptr;
}

WEI_Object WebXMLHttpRequest_create()
{
  WEI_Object cls = WebObject_getProperty(WEI_GLOBAL_THIS, "XMLHttpRequest");
  WEI_Object result = WEI_objectCreate(cls);
  WEI_objectRelease(cls);
  return result;
}

int WebXMLHttpRequest_open(WEI_Object xhr, const char* method, const char* url)
{
  WebString* openStr = WebString_create("open");
  WebString* methodStr = WebString_create(method);
  WebString* urlStr = WebString_create(url);

  int result = WEI_callIntegerMethod2(xhr, wobject_idx(openStr), wobject_idx(methodStr), wobject_idx(urlStr));

  WebString_destroy(urlStr);
  WebString_destroy(methodStr);
  WebString_destroy(openStr);

  return result;
}

int WebXMLHttpRequest_openGET(WEI_Object xhr, const WebString* url)
{
  WebString* openStr = WebString_create("open");
  WebString* methodStr = WebString_create("GET");

  int result = WEI_callIntegerMethod2(xhr, wobject_idx(openStr), wobject_idx(methodStr), wobject_idx(url));

  WebString_destroy(methodStr);
  WebString_destroy(openStr);

  return result;
}

int WebXMLHttpRequest_send(WEI_Object xhr, WEI_Object body)
{
  WebString* sendStr = WebString_create("send");
  int result = WEI_callIntegerMethod1(xhr, wobject_idx(sendStr), body);
  WebString_destroy(sendStr);

  return result;
}

WEI_Object WebXMLHttpRequest_response(WEI_Object xhr)
{
  WebString* responseStr = WebString_create("response");
  WEI_Object result =  WEI_getObjectProperty(xhr, wobject_idx(responseStr));
  WebString_destroy(responseStr);

  return result;
}

int WebXMLHttpRequest_setResponseType(WEI_Object xhr, const char* type)
{
  WebString* responseTypeStr = WebString_create("responseType");
  WebString* arraybufferStr = WebString_create(type);

  int result = WEI_setObjectProperty(xhr, wobject_idx(responseTypeStr), wobject_idx(arraybufferStr));

  WebString_destroy(arraybufferStr);
  WebString_destroy(responseTypeStr);

  return result;
}

int WebXMLHttpRequest_readyState(WEI_Object xhr)
{
  WebString* readyStateStr = WebString_create("readyState");
  int result = WEI_getIntegerProperty(xhr, wobject_idx(readyStateStr));
  WebString_destroy(readyStateStr);

  return result;
}

int WebXMLHttpRequest_addOnReadyStateChange(WEI_Object xhr, WEI_PerformCallback1* callback, void* userdata)
{
  return WebObject_addEventListener(xhr, "readystatechange", callback, userdata);
}

WebFunction* WebXMLHttpRequest_addOnLoad(WEI_Object xhr, WEI_PerformCallback1* callback, void* userdata)
{
  WebString* type = WebString_create("load");
  WEI_Object listenerObj = WEI_addEventListener(xhr, wobject_idx(type), callback, userdata);
  WebString_destroy(type);
  return wobject_ptr(WebFunction, listenerObj);
}

WebFunction* WebXMLHttpRequest_addOnError(WEI_Object xhr, WEI_PerformCallback1* callback, void* userdata)
{
  WebString* type = WebString_create("error");
  WEI_Object listenerObj = WEI_addEventListener(xhr, wobject_idx(type), callback, userdata);
  WebString_destroy(type);
  return wobject_ptr(WebFunction, listenerObj);
}

int WebXMLHttpRequest_removeOnLoad(WEI_Object xhr, WebFunction* listener)
{
  WebString* type = WebString_create("load");
  int res = WEI_removeEventListener(xhr, wobject_idx(type), wobject_idx(listener));
  WebString_destroy(type);
  return res;
}

int WebXMLHttpRequest_removeOnError(WEI_Object xhr, WebFunction* listener)
{
  WebString* type = WebString_create("error");
  int res = WEI_removeEventListener(xhr, wobject_idx(type), wobject_idx(listener));
  WebString_destroy(type);
  return res;
}
