/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/web/arraybuffer.h>
#include <wasmux/web/string.h>

WebArrayBuffer* WebArrayBuffer_create(unsigned size, bool shared)
{
	WebString* clsStr = WebString_create(shared ? "SharedArrayBuffer" : "ArrayBuffer");
	WEI_Object cls = WEI_getObjectProperty(WEI_GLOBAL_THIS, wobject_idx(clsStr));
	WebString_destroy(clsStr);

	WEI_Object sizeObj = WEI_numberCreate(static_cast<int>(size));
  WEI_Object result = WEI_objectCreate1(cls, sizeObj);
	WEI_objectRelease(sizeObj);

  WEI_objectRelease(cls);
  return wobject_ptr(WebArrayBuffer, result);
}

void WebArrayBuffer_destroy(WebArrayBuffer* thiz)
{
  WEI_objectRelease(wobject_idx(thiz));
}

unsigned WebArrayBuffer_byteLength(const WebArrayBuffer* thiz)
{
	WebString* byteLengthStr = WebString_create("byteLength");
  int byteLength = WEI_getIntegerProperty(wobject_idx(thiz), wobject_idx(byteLengthStr));
	WebString_destroy(byteLengthStr);
  return static_cast<unsigned>(byteLength);
}

WebArrayBuffer* WebArrayBuffer_clone(const WebArrayBuffer* thiz)
{
	WEI_Object object = WEI_objectRetain(wobject_idx(thiz));
	return wobject_ptr(WebArrayBuffer, object);
}

unsigned WebArrayBuffer_setBytes(WebArrayBuffer* thiz, unsigned offset, const void* data, unsigned size)
{
	return WEI_memoryCopy(wobject_idx(thiz), reinterpret_cast<void*>(offset), WEI_KERNEL_MEMORY_ID, data, size);
}

Uint8ClampedArray* WebArrayBuffer_toUint8ClampedArray(WebArrayBuffer* thiz)
{
	WebString* clsStr = WebString_create("Uint8ClampedArray");
	WEI_Object cls = WEI_getObjectProperty(WEI_GLOBAL_THIS, wobject_idx(clsStr));
	WebString_destroy(clsStr);

  WEI_Object result = WEI_objectCreate1(cls, wobject_idx(thiz));
	return wobject_ptr(Uint8ClampedArray, result);
}

void Uint8ClampedArray_destroy(Uint8ClampedArray* thiz)
{
  WEI_objectRelease(wobject_idx(thiz));
}
