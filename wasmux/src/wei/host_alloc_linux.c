/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/platform.h>
#include <wasmux/log.h>
#include <wasmux/wasm_page.h>

#include "host_alloc.h"

#if defined(WA_OS_LINUX)

#include <stdlib.h>
#include <errno.h>

void* host_page_alloc(unsigned order)
{
  void* ptr = aligned_alloc(WA_MEMORY_PAGE_SIZE, order * WA_MEMORY_PAGE_SIZE);
  if (ptr == NULL) {
    LOG_ERROR("Can't allocate memory (%i)", errno);
  }
  return ptr;
}

void host_page_free(void* ptr)
{
  free(ptr);
}

#endif
