/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WORKER_THREAD_H
#define _WASMUX_WORKER_THREAD_H

#include <wasmux/types.h>
#include <wasmux/stack_pointer.h>
#include <wasmux/wasm_page.h>
#include <wasmux/wasm_header.h>
#include <wasmux/wei.h>
#include <wasmux/web/webassembly.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebWorkerInstance {
  char name[32];

  void* stack;
  WEI_Object worker;
  void* context;

  // TODO: This data is here for start up use only,
  //       it will need to be transferred to those who really need it
  WEI_Object userModule;
  WebAssemblyMemory* userMemory;
  struct wasm_memory_info meminfo;

} WebWorkerInstance;

#ifdef WA_OS_WINDOWS
extern void* g_mainInstance;
#define WebGetMainInstance() g_mainInstance
#else
#define WebGetMainInstance() NULL
#endif

static inline struct WebWorkerInstance* WebGetCurrentWorkerInstance()
{
  return (struct WebWorkerInstance*)((uintptr_t)__get_stack_pointer() & WA_STACK_MASK);
}

static inline bool WebIsMainInstance()
{
  return WebGetCurrentWorkerInstance() == WebGetMainInstance();
}

static inline bool WebIsWorkerInstance()
{
  return WebGetCurrentWorkerInstance() != WebGetMainInstance();
}

unsigned WebGetCurrentWorkerId();

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WORKER_THREAD_H */
