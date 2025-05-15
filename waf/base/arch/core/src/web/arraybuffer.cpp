/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/arraybuffer.h>
#include <wasmux/web/string.h>
#include <wasmux/cxx/ObjectCast.h>

WebArrayBuffer* WebArrayBuffer_create(unsigned size, bool shared)
{
	WebString* clsStr = WebString_create(shared ? "SharedArrayBuffer" : "ArrayBuffer");
	WEI_Object cls = WEI_getObjectProperty(WEI_GLOBAL_THIS, object_idx_cast(clsStr));
	WebString_destroy(clsStr);

	WEI_Object sizeObj = WEI_numberCreate(static_cast<int>(size));
  WEI_Object result = WEI_objectCreate1(cls, sizeObj);
	WEI_objectRelease(sizeObj);

  WEI_objectRelease(cls);
  return object_ptr_cast<WebArrayBuffer>(result);
}

void WebArrayBuffer_destroy(WebArrayBuffer* thiz)
{
  WEI_objectRelease(object_idx_cast(thiz));
}

unsigned WebArrayBuffer_byteLength(const WebArrayBuffer* thiz)
{
	WebString* byteLengthStr = WebString_create("byteLength");
  int byteLength = WEI_getIntegerProperty(object_idx_cast(thiz), object_idx_cast(byteLengthStr));
	WebString_destroy(byteLengthStr);
  return static_cast<unsigned>(byteLength);
}

WebArrayBuffer* WebArrayBuffer_clone(const WebArrayBuffer* thiz)
{
	WEI_Object object = WEI_objectRetain(object_idx_cast(thiz));
	return object_ptr_cast<WebArrayBuffer>(object);
}

unsigned WebArrayBuffer_setBytes(WebArrayBuffer* thiz, unsigned offset, const void* data, unsigned size)
{
	return WEI_memoryCopy(object_idx_cast(thiz), reinterpret_cast<void*>(offset), WEI_KERNEL_MEMORY_ID, data, size);
}

Uint8ClampedArray* WebArrayBuffer_toUint8ClampedArray(WebArrayBuffer* thiz)
{
	WebString* clsStr = WebString_create("Uint8ClampedArray");
	WEI_Object cls = WEI_getObjectProperty(WEI_GLOBAL_THIS, object_idx_cast(clsStr));
	WebString_destroy(clsStr);

  WEI_Object result = WEI_objectCreate1(cls, object_idx_cast(thiz));
	return object_ptr_cast<Uint8ClampedArray>(result);
}

void Uint8ClampedArray_destroy(Uint8ClampedArray* thiz)
{
  WEI_objectRelease(object_idx_cast(thiz));
}
