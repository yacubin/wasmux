/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/object.h>
#include <wasmux/web/string.h>
#include <wasmux/cxx/ObjectCast.h>

WEI_Object WebObject_create()
{
  WEI_Object cls = WebObject_getProperty(WEI_GLOBAL_THIS, "Object");
  WEI_Object result = WEI_objectCreate(cls);
  WEI_objectRelease(cls);
  return result;
}

WEI_Object WebObject_getProperty(WEI_Object object, const char* name)
{
  WebString* nameObj = WebString_create(name);
  WEI_Object result = WEI_getObjectProperty(object, object_idx_cast(nameObj));
  WebString_destroy(nameObj);
  return result;
}

int WebObject_setProperty(WEI_Object object, const char* name, WEI_Object value)
{
  WebString* nameObj = WebString_create(name);
  int result = WEI_setObjectProperty(object, object_idx_cast(nameObj), value);
  WebString_destroy(nameObj);
  return result;
}

WEI_Object WebObject_callObjMethod(WEI_Object object, const char* method, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4)
{
  WebString* methodObj = WebString_create(method);
  WEI_Object result = WEI_callObjectMethod4(object, object_idx_cast(methodObj), arg1, arg2, arg3, arg4);
  WebString_destroy(methodObj);
  return result;
}

int WebObject_addEventListener(WEI_Object object, const char* type, WEI_PerformCallback1* callback, void* userdata)
{
  WebString* typeStr = WebString_create(type);
  int result = WEI_addEventListener(object, object_idx_cast(typeStr), callback, userdata);
  WebString_destroy(typeStr);
  return result;
}

int WebObject_getIntegerProperty(WEI_Object object, const WebString* name)
{
  return WEI_getIntegerProperty(object, object_idx_cast(name));
}
