/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <wasmux/worker_instance.h>
#include <wasmux/assert.h>
#include <wasmux/errno.h>
#include <wasmux/notify_waiter.h>
#include <wasmux/wasm_page.h>
#include <wasmux/log.h>
#include <wasmux/web/string.h>
#include <wasmux/cxx/Characters.h>
#include <wasmux/cxx/ObjectCast.h>

#include <wasmux/memory_alloc.h>
#include <wasmux/web/worker.h>
#include <wasmux/web/webassembly.h>
#include <wasmux/main_loop.h>

#ifdef WA_OS_WINDOWS
#include "windows/WorkerThreadContext.h"
#endif

extern "C" void WebWorkerInstanceInit(void* stack);

static void workerInstanceRun(void* userdata)
{
  auto instance = reinterpret_cast<WebWorkerInstance*>(userdata);

  WebString* name = WebString_create(instance->name);
  instance->worker =  WebWorker_create(WEI_SCRIPT_URL_ID, object_idx_cast(name));
  WebString_destroy(name);

  WEI_workerInstance(instance->worker);
  WEI_workerPerform(instance->worker, &WebWorkerInstanceInit, instance->stack);
}

void WebWorkerInstance_init(WebWorkerInstance* instance, const char* name)
{
  WAF::charactersCopy(instance->name, name);

  /*
   * The stack cannot point to the top because of receiving
   * a worker instance at the bottom of the stack
   * __stack_pointer & WASM_MEMORY_PAGE_MASK
   */
  instance->stack = reinterpret_cast<char*>(instance) + WA_STACK_SIZE - sizeof(void*);
  instance->worker = WEI_UNDEFINED_OBJECT;
  instance->userModule = WEI_UNDEFINED_OBJECT;
  instance->userMemory = WEI_UNDEFINED_OBJECT;
  instance->meminfo.min_value = 0;
  instance->meminfo.max_value = 0;
  instance->meminfo.has_max_value = false;
  instance->meminfo.is_shared = false;

#ifdef WA_OS_WINDOWS
  instance->context = WEI::WorkerThreadContext::create();
#else
  instance->context = nullptr;
#endif
}

WebWorkerInstance* WebWorkerInstance_create(const char* name)
{
  auto instance = reinterpret_cast<WebWorkerInstance*>(WebAllocPages(1));
  WA_ASSERT(instance != nullptr);

  WebWorkerInstance_init(instance, name);

  return instance;
}

int WebWorkerInstance_run(struct WebWorkerInstance* instance)
{
  WebMainLoopDispatch(&workerInstanceRun, instance, LP_ASYNC);
  return 0;
}

static void startModuleHandler(void* userdata, WEI_Object module)
{
  (void)userdata;
  auto instance = WebGetCurrentWorkerInstance();
  uint32_t max_value = instance->meminfo.has_max_value ? instance->meminfo.max_value : 100; // FIXME
  WEI_Object memory = WEI_memoryCreate(instance->meminfo.min_value, max_value, instance->meminfo.is_shared);

  instance->userModule = module;
  instance->userMemory = memory;

  WEI_userInstanceStart(module, memory);
}

int WebWorkerInstance_startModule(struct WebWorkerInstance* instance, WEI_Object module, struct wasm_memory_info* meminfo)
{
  if (!WebIsMainInstance()) {
    WA_UNREACHABLE();
    return -ECANCELED;
  }

  WebString* name = WebString_create(instance->name);
  instance->worker =  WebWorker_create(WEI_SCRIPT_URL_ID, object_idx_cast(name));
  WebString_destroy(name);

  instance->meminfo = *meminfo;

  WEI_workerInstance(instance->worker);
  WEI_workerPerform(instance->worker, &WebWorkerInstanceInit, instance->stack);
  WEI_workerPerform1(instance->worker, &startModuleHandler, nullptr, module);

  return 0;
}

void startThreadImpl(struct WebWorkerInstance* instance, WEI_PerformCallback* callback, void* userdata)
{
  WebString* name = WebString_create(instance->name);
  instance->worker =  WebWorker_create(WEI_SCRIPT_URL_ID, object_idx_cast(name));
  WebString_destroy(name);

  WEI_workerInstance(instance->worker);
  WEI_workerPerform(instance->worker, &WebWorkerInstanceInit, instance->stack);

  if (callback) {
    WEI_workerPerform(instance->worker, callback, userdata);
  }
}

int WebWorkerInstance_startThread(struct WebWorkerInstance* instance, WEI_PerformCallback* callback, void* userdata)
{
  if (!WebIsMainInstance()) {
    WA_UNREACHABLE();
    return -ECANCELED;
  }

  startThreadImpl(instance, callback, userdata);
  return 0;
}

struct StartBinaryData {
  notify_waiter_t signal;
  WebWorkerInstance* instance;
  struct wasm_memory_info* meminfo;
  int ec;
};

static void onResultCompile(void* userdata, WEI_Object module)
{
	auto data = reinterpret_cast<StartBinaryData*>(userdata);

  WebWorkerInstance* instance = data->instance;
  data->ec = WebWorkerInstance_startModule(instance, module, data->meminfo);

	notify_waiter_notify(&data->signal);
}

static void onErrorCompile(void* userdata, WEI_Object reason)
{
	auto data = reinterpret_cast<StartBinaryData*>(userdata);

  LOG_INFO("Reason %u", reason);
  data->ec = -EIO;

	notify_waiter_notify(&data->signal);
}

static void onStartBinaryHandler(void* userdata, WEI_Object buffer)
{
  Uint8ClampedArray* bytes = WebArrayBuffer_toUint8ClampedArray(object_ptr_cast<WebArrayBuffer>(buffer));
  WEI_Object promise = WebAssembly_compile(object_idx_cast(bytes));
  Uint8ClampedArray_destroy(bytes);
  WEI_promiseThen(promise, &onResultCompile, &onErrorCompile, userdata);
  WEI_objectRelease(promise);
}

int WebWorkerInstance_startBinarySync(struct WebWorkerInstance* instance, WebArrayBuffer* buffer, struct wasm_memory_info* meminfo)
{
  WA_ASSERT(!WebIsMainInstance());

  StartBinaryData data;
  notify_waiter_init(&data.signal);
  data.instance = instance;
  data.meminfo = meminfo;
  data.ec = EIO;

  int ec = WEI_postMessage1(&onStartBinaryHandler, &data, object_idx_cast(buffer));
	if (ec < 0)
		return ec;

	notify_waiter_wait(&data.signal, NOTIFY_WAITER_INFINITE);
	return data.ec;
}
