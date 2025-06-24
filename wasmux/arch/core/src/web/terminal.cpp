/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/terminal.h>
#include <wasmux/errno.h>
#include <wasmux/notify_waiter.h>
#include <wasmux/web/string.h>
#include <wasmux/web/arraybuffer.h>

struct BaseSyncData {
  notify_waiter_t signal;
  int ec{-EINVAL};

  BaseSyncData()
  {
    notify_waiter_init(&signal);
  }

  void wait()
  {
    notify_waiter_wait(&signal, NOTIFY_WAITER_INFINITE);
  }

  void notify()
  {
    notify_waiter_notify(&signal);
  }
};

void WebTerminalManager_init(WebTerminalManager* thiz)
{
}

void WebTerminalManager_finalize(WebTerminalManager* thiz)
{
}

struct OpenSyncData : BaseSyncData {
	WebTerminal* terminal{nullptr};
};

static void onOpenHandler(void* userdata)
{
	auto data = reinterpret_cast<OpenSyncData*>(userdata);

	WebString* clsStr = WebString_create("IODrv");
  WEI_Object cls = WEI_getObjectProperty(WEI_GLOBAL_THIS, wobject_idx(clsStr));

  data->terminal = wobject_ptr(WebTerminal, WEI_objectCreate(cls));
	data->ec = 0;

  WEI_objectRelease(cls);
	WebString_destroy(clsStr);

  data->notify();
}

WebTerminal* WebTerminalManager_openSync(WebTerminalManager* thiz, int* errorCode)
{
  OpenSyncData data;

  int ec = WEI_postMessage(&onOpenHandler, &data);
  if (ec < 0) {
    if (errorCode) {
      *errorCode = ec;
    }
    return nullptr;
  }

  data.wait();

  if (errorCode) {
    *errorCode = data.ec;
	}

  return data.terminal;
}

struct WriteSyncData : BaseSyncData {
	WebTerminal* terminal;
  const char* buf;
  unsigned len;
};

static void onWriteHandler(void* userdata, WEI_Object memoryObj)
{
	auto data = reinterpret_cast<WriteSyncData*>(userdata);
  
  WebString* stdoutStr = WebString_create("stdout");
  WEI_Object textObj = WEI_stringCreate(memoryObj, data->buf, data->len);

  int len = WEI_callIntegerMethod1(wobject_idx(data->terminal), wobject_idx(stdoutStr), textObj);

  WEI_objectRelease(textObj);
  WebString_destroy(stdoutStr);

  data->ec = len;
	data->notify();
}

int WebTerminalManager_writeSync(WebTerminalManager* thiz, WebTerminal* terminal, WEI_Object mem, const char* buf, unsigned len)
{
	struct WriteSyncData data;

	data.terminal = terminal;
	data.buf = buf;
	data.len = len;

  int ec = WEI_postMessage1(&onWriteHandler, &data, mem);
	if (ec < 0)
    return ec;

  data.wait();
	return data.ec;
}

struct WriteStrSyncData : BaseSyncData {
	WebTerminal* terminal;
};

static void onWriteStrHandler(void* userdata, WEI_Object textObj)
{
	auto data = reinterpret_cast<WriteStrSyncData*>(userdata);
  
  WebString* stdoutStr = WebString_create("stdout");
  int len = WEI_callIntegerMethod1(wobject_idx(data->terminal), wobject_idx(stdoutStr), textObj);
  WebString_destroy(stdoutStr);

  data->ec = len;
	data->notify();
}

int WebTerminalManager_writeStrSync(WebTerminalManager* thiz, WebTerminal* terminal, WebString* str)
{
	struct WriteStrSyncData data;

	data.terminal = terminal;

  int ec = WEI_postMessage1(&onWriteStrHandler, &data, wobject_idx(str));
	if (ec < 0)
    return ec;

  data.wait();
	return data.ec;
}

struct CloseSyncData : BaseSyncData {
	WebTerminal* terminal;
};

static void onCloseHandler(void* userdata)
{
	auto data = reinterpret_cast<CloseSyncData*>(userdata);

	WEI_objectRelease(wobject_idx(data->terminal));
	data->ec = 0;

  data->notify();
}

int WebTerminalManager_closeSync(WebTerminalManager* thiz, WebTerminal* terminal)
{
  CloseSyncData data;
	data.terminal = terminal;

  int ec = WEI_postMessage(&onOpenHandler, &data);
  if (data.ec < 0)
    return ec;

  data.wait();
  return data.ec;
}
