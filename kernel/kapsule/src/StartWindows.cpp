/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/export.h>
#include <wasmux/memory_alloc.h>
#include <wasmux/wasm_page.h>
#include <wasmux/sprintf.h>
#include <wasmux/log.h>
#include <wasmux/wei/main_loop.h>
#include <wasmux/web/console.h>
#include <wasmux/win32/BaseThreadContext.h>

#include <windows.h>

__EXPORT void __start_kernel();

#define WM_USER_DISPATCH (WM_USER + 1)

static DWORD WINAPI thread_func(LPVOID lpParam)
{
  void* stack = nullptr;
  asm("mov %%esp, %0" : "=r" (stack));

  LOG_INFO("Thread stack %p\n", stack);

  return 0;
}

static void entryPoint(void* ptr)
{
  void* stack = WebAllocPages(WA_STACK_PAGES);
  LOG_INFO("Alloc stack %p\n", stack);
  //HANDLE threadHnd = CreateThread(NULL, WASM_STACK_SIZE, thread_func, NULL, 0, NULL);
  HANDLE hThread = CreateThread(nullptr, 0, thread_func, nullptr, CREATE_SUSPENDED, nullptr);
  if (!hThread) {
    LOG_ERROR("Failed to create thread, error: %u", static_cast<unsigned>(GetLastError()));
    WebFreePages(stack, WA_STACK_PAGES);
    return;
  }

  CONTEXT context;
  context.ContextFlags = CONTEXT_FULL;
  if (!GetThreadContext(hThread, &context)) {
    LOG_ERROR("Failed to get thread context, error: %u", static_cast<unsigned>(GetLastError()));
    WebFreePages(stack, WA_STACK_PAGES);
    CloseHandle(hThread);
    return;
  }

  context.Esp = reinterpret_cast<DWORD>(stack) + WA_STACK_SIZE - sizeof(void*);
  if (!SetThreadContext(hThread, &context)) {
    LOG_ERROR("Failed to set thread context, error: %u", static_cast<unsigned>(GetLastError()));
    WebFreePages(stack, WA_STACK_PAGES);
    CloseHandle(hThread);
    return;
  }

  ResumeThread(hThread);
}

__EXPORT void _start()
{
  __start_kernel();

  entryPoint(nullptr);
  WebMainLoopDispatch(&entryPoint, nullptr, LP_ASYNC);

  WEI::currentLooperRun();

  MessageBox(NULL, "Hello, World 2!", "Greetings", MB_OK);
  ExitProcess(0);
}
