/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#define __SSIZE_T__ int // For windows.h

#include <wasmux-config.h>
#include <wasmux/platform.h>
#include <wasmux/log.h>
#include <wasmux/wasm_page.h>

#include "host_alloc.h"

#if defined(WA_OS_WINDOWS)

#include <windows.h>

void* host_page_alloc(unsigned order)
{
  void* ptr = VirtualAlloc(NULL, order * WA_MEMORY_PAGE_SIZE,
                        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  if (ptr == NULL) {
    LOG_ERROR("Can't allocate memory (%u)", (unsigned)GetLastError());
  }
  return ptr;
}

void host_page_free(void* ptr)
{
  VirtualFree(ptr, 0, MEM_RELEASE);
}

#endif
