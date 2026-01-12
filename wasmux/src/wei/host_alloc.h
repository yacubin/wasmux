/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEI_HOST_ALLOC_H
#define _WASMUX_WEI_HOST_ALLOC_H

#include <wasmux/export.h>

__EXPORT void* host_page_alloc(unsigned order);
__EXPORT void host_page_free(void*);

#endif /* _WASMUX_WEI_HOST_ALLOC_H */
