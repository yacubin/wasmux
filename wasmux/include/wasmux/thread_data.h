/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_THREAD_DATA_H
#define _WASMUX_THREAD_DATA_H

#include <wasmux/types.h>

struct wasmux_thread_data {
  int errcode;
  char buffer[256];
};

#endif /* _WASMUX_THREAD_DATA_H */
