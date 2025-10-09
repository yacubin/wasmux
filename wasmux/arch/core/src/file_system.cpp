/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/file_system.h>
#include <wasmux/errno.h>
#include <wasmux/notify_waiter.h>
#include <wasmux/log.h>
#include <wasmux/wei.h>
#include <wasmux/web/string.h>
#include <wasmux/memory_alloc.h>
#include <wasmux/web/object.h>
#include <wasmux/wei/main_loop.h>
#include <wasmux/web/xmlhttprequest.h>
#include <wasmux/web/console.h>

void WebMainFileSystem_init(WebMainFileSystem* thiz)
{
	thiz->rootObj = WEI_UNDEFINED_OBJECT;
}

static void onFinalizeHandler(void* userdata)
{
	auto root = reinterpret_cast<WebObject*>(userdata);
  WEI_objectRelease(wobject_idx(root));
}

void WebMainFileSystem_finalize(WebMainFileSystem* thiz)
{
	if (thiz->rootObj)
	  WEI_postMessage(&onFinalizeHandler, wobject_ptr(WebObject, thiz->rootObj));
}

struct StatSyncData {
	WebMainFileSystem* impl;
	notify_waiter_t signal;
	int ec;
	WebMainFileStat* stat;
	// XHR
	WEI_Object xhrObj;
	WebString* path;
	WebFunction* loadFn;
	WebFunction* errorFn;
};

static void onStatLoadRequest(void* userdata, WEI_Object event)
{
	auto data = reinterpret_cast<StatSyncData*>(userdata);

	WebString* statusStr = WebString_create("status");
  int status = WebObject_getIntegerProperty(data->xhrObj, statusStr);
	WebString_destroy(statusStr);

	WEI_Object bytes = WebXMLHttpRequest_response(data->xhrObj);
	if (!bytes)
	  data->ec = -ENOENT;
	else {
		WEI_setObjectProperty(data->impl->rootObj, wobject_idx(data->path), bytes);
	  data->stat->size = WebArrayBuffer_byteLength(wobject_ptr(WebArrayBuffer, bytes));
	  data->ec = 0;
		WEI_objectRelease(bytes);
	}

  WebXMLHttpRequest_removeOnLoad(data->xhrObj, data->loadFn);
  WebXMLHttpRequest_removeOnError(data->xhrObj, data->errorFn);
	WEI_objectRelease(data->xhrObj);
	WebString_destroy(data->path);

	notify_waiter_notify(&data->signal);
}

static void onStatErrorRequest(void* userdata, WEI_Object event)
{
	auto data = reinterpret_cast<StatSyncData*>(userdata);

  data->ec = -ENOENT;

  WebXMLHttpRequest_removeOnLoad(data->xhrObj, data->loadFn);
  WebXMLHttpRequest_removeOnError(data->xhrObj, data->errorFn);
	WEI_objectRelease(data->xhrObj);
	WebString_destroy(data->path);

	notify_waiter_notify(&data->signal);
}

static void onStatHandler(void* userdata, WEI_Object pathObj)
{
	auto data = reinterpret_cast<StatSyncData*>(userdata);
	if (!data->impl->rootObj)
		data->impl->rootObj = WebObject_create();
	else {
    auto bytes = wobject_ptr(WebArrayBuffer, WEI_getObjectProperty(data->impl->rootObj, pathObj));
		if (bytes) {
	    data->stat->size = WebArrayBuffer_byteLength(bytes);
			data->ec = 0;
      notify_waiter_notify(&data->signal);
			return;
		}
	}

  data->path = wobject_ptr(WebString, WEI_objectRetain(pathObj));
  data->xhrObj = WebXMLHttpRequest_create();
  data->loadFn = WebXMLHttpRequest_addOnLoad(data->xhrObj, &onStatLoadRequest, data);
  data->errorFn = WebXMLHttpRequest_addOnError(data->xhrObj, &onStatErrorRequest, data);
  WebXMLHttpRequest_setResponseType(data->xhrObj, "arraybuffer");
  WebXMLHttpRequest_openGET(data->xhrObj, data->path);
  WebXMLHttpRequest_send(data->xhrObj, WEI_NULL_OBJECT);
}

int WebMainFileSystem_statSync(WebMainFileSystem* thiz, const WebString* path, WebMainFileStat* stat)
{
	struct StatSyncData data;

  notify_waiter_init(&data.signal);
	data.ec = -EIO;
	data.impl = thiz;
	data.stat = stat;

  int ec = WEI_postMessage1(&onStatHandler, &data, wobject_idx(path));
	if (ec < 0)
		return ec;

	notify_waiter_wait(&data.signal, NOTIFY_WAITER_INFINITE);
	return data.ec;
}

struct OpenSyncData {
	WebMainFileSystem* impl;
	notify_waiter_t signal;
	int ec;
	// XHR
	WEI_Object xhrObj;
	WebFunction* loadFn;
	WebFunction* errorFn;
	WebString* path;
};

static void onOpenLoadRequest(void* userdata, WEI_Object event)
{
	auto data = reinterpret_cast<OpenSyncData*>(userdata);

	WebString* statusStr = WebString_create("status");
  int status = WebObject_getIntegerProperty(data->xhrObj, statusStr);
	WebString_destroy(statusStr);

	WEI_Object bytes = WebXMLHttpRequest_response(data->xhrObj);
	if (!bytes)
	  data->ec = -ENOENT;
	else {
		WEI_setObjectProperty(data->impl->rootObj, wobject_idx(data->path), bytes);
    data->ec = static_cast<int>(WEI_objectRetain(bytes));
		WEI_objectRelease(bytes);
	}

  WebXMLHttpRequest_removeOnLoad(data->xhrObj, data->loadFn);
  WebXMLHttpRequest_removeOnError(data->xhrObj, data->errorFn);
	WEI_objectRelease(data->xhrObj);
	WebString_destroy(data->path);

	notify_waiter_notify(&data->signal);
}

static void onOpenErrorRequest(void* userdata, WEI_Object event)
{
	auto data = reinterpret_cast<StatSyncData*>(userdata);

  data->ec = -ENOENT;

  WebXMLHttpRequest_removeOnLoad(data->xhrObj, data->loadFn);
  WebXMLHttpRequest_removeOnError(data->xhrObj, data->errorFn);
	WEI_objectRelease(data->xhrObj);
	WebString_destroy(data->path);

	notify_waiter_notify(&data->signal);
}

static void onOpenHandler(void* userdata, WEI_Object pathObj)
{
	auto data = reinterpret_cast<OpenSyncData*>(userdata);
	if (!data->impl->rootObj)
		data->impl->rootObj = WebObject_create();
	else {
    auto bytes = WEI_getObjectProperty(data->impl->rootObj, pathObj);
		if (bytes) {
			data->ec = static_cast<int>(WEI_objectRetain(bytes));
		  WEI_objectRelease(bytes);
      notify_waiter_notify(&data->signal);
			return;
		}
	}

  data->path = wobject_ptr(WebString, WEI_objectRetain(pathObj));
  data->xhrObj = WebXMLHttpRequest_create();
  data->loadFn = WebXMLHttpRequest_addOnLoad(data->xhrObj, &onOpenLoadRequest, data);
  data->errorFn = WebXMLHttpRequest_addOnError(data->xhrObj, &onOpenErrorRequest, data);
  WebXMLHttpRequest_setResponseType(data->xhrObj, "arraybuffer");
  WebXMLHttpRequest_openGET(data->xhrObj, data->path);
  WebXMLHttpRequest_send(data->xhrObj, WEI_NULL_OBJECT);
}

int WebMainFileSystem_openSync(WebMainFileSystem* thiz, const WebString* path)
{
	struct OpenSyncData data;

  notify_waiter_init(&data.signal);
	data.ec = -EIO;
	data.impl = thiz;

  int ec = WEI_postMessage1(&onOpenHandler, &data, wobject_idx(path));
	if (ec < 0)
		return ec;

	notify_waiter_wait(&data.signal, NOTIFY_WAITER_INFINITE);
	return data.ec;
}

struct ReadSyncData {
	WebMainFileSystem* impl;
	notify_waiter_t signal;
	int ec;
	int fd;
	void* buf;
	unsigned size;
	unsigned offset;
};

static void onReadHandler(void* userdata)
{
	auto data = reinterpret_cast<ReadSyncData*>(userdata);
	if (!data->impl->rootObj)
    data->ec = -ENOENT;
	else {
		auto buffer = wobject_ptr(WebArrayBuffer, data->fd);
		unsigned size = WebArrayBuffer_byteLength(buffer);
		if (data->offset < size) {
			size -= data->offset;
			if (data->size < size)
			  size = data->size;
			WEI_memoryCopy(WEI_KERNEL_MEMORY_ID, data->buf, wobject_idx(buffer), reinterpret_cast<void*>(data->offset), size);
      data->ec = size;
		}
		else {
      data->ec = 0;
		}
	}

  notify_waiter_notify(&data->signal);
}

int WebMainFileSystem_readSync(WebMainFileSystem* thiz, int fd, unsigned offset, void* buf, unsigned size)
{
	struct ReadSyncData data;

	WebConsolePrint("webfs readSync fd %i off %u len %u", fd, offset, size);

  notify_waiter_init(&data.signal);
	data.ec = -EIO;
	data.impl = thiz;
	data.fd = fd;
	data.buf = buf;
	data.size = size;
	data.offset = offset;

  int ec = WEI_postMessage(&onReadHandler, &data);
	if (ec < 0)
		return ec;

	notify_waiter_wait(&data.signal, NOTIFY_WAITER_INFINITE);
	return data.ec;
}

struct AccessSyncData {
	WebMainFileSystem* impl;
	notify_waiter_t signal;
	int ec;
	int mode;
	// XHR
	WEI_Object xhrObj;
	WebString* path;
	WebFunction* loadFn;
	WebFunction* errorFn;
};

static void onAccessLoadRequest(void* userdata, WEI_Object event)
{
	auto data = reinterpret_cast<StatSyncData*>(userdata);

	WebString* statusStr = WebString_create("status");
  int status = WebObject_getIntegerProperty(data->xhrObj, statusStr);
	WebString_destroy(statusStr);

	WEI_Object bytes = WebXMLHttpRequest_response(data->xhrObj);
	if (!bytes)
	  data->ec = -ENOENT;
	else {
		WEI_setObjectProperty(data->impl->rootObj, wobject_idx(data->path), bytes);
	  data->stat->size = WebArrayBuffer_byteLength(wobject_ptr(WebArrayBuffer, bytes));
	  data->ec = 0;
		WEI_objectRelease(bytes);
	}

  WebXMLHttpRequest_removeOnLoad(data->xhrObj, data->loadFn);
  WebXMLHttpRequest_removeOnError(data->xhrObj, data->errorFn);
	WEI_objectRelease(data->xhrObj);
	WebString_destroy(data->path);

	notify_waiter_notify(&data->signal);
}

static void onAccessErrorRequest(void* userdata, WEI_Object event)
{
	auto data = reinterpret_cast<StatSyncData*>(userdata);

  data->ec = -ENOENT;

  WebXMLHttpRequest_removeOnLoad(data->xhrObj, data->loadFn);
  WebXMLHttpRequest_removeOnError(data->xhrObj, data->errorFn);
	WEI_objectRelease(data->xhrObj);
	WebString_destroy(data->path);

	notify_waiter_notify(&data->signal);
}

static void onAccessHandler(void* userdata, WEI_Object pathObj)
{
	auto data = reinterpret_cast<StatSyncData*>(userdata);
	if (!data->impl->rootObj)
		data->impl->rootObj = WebObject_create();
	else {
    auto bytes = wobject_ptr(WebArrayBuffer, WEI_getObjectProperty(data->impl->rootObj, pathObj));
		if (bytes) {
			data->ec = 0;
      notify_waiter_notify(&data->signal);
			return;
		}
	}

  data->path = wobject_ptr(WebString, WEI_objectRetain(pathObj));
  data->xhrObj = WebXMLHttpRequest_create();
  data->loadFn = WebXMLHttpRequest_addOnLoad(data->xhrObj, &onAccessLoadRequest, data);
  data->errorFn = WebXMLHttpRequest_addOnError(data->xhrObj, &onAccessErrorRequest, data);
  WebXMLHttpRequest_setResponseType(data->xhrObj, "arraybuffer");
  WebXMLHttpRequest_openGET(data->xhrObj, data->path);
  WebXMLHttpRequest_send(data->xhrObj, WEI_NULL_OBJECT);
}

int WebMainFileSystem_accessSync(WebMainFileSystem* thiz, const WebString* path, int mode)
{
	struct AccessSyncData data;

  notify_waiter_init(&data.signal);
	data.ec = -EIO;
	data.impl = thiz;
	data.mode = mode;

  int ec = WEI_postMessage1(&onAccessHandler, &data, wobject_idx(path));
	if (ec < 0)
		return ec;

	notify_waiter_wait(&data.signal, NOTIFY_WAITER_INFINITE);
	return data.ec;
}
