/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/thread_local.h>
#include <bits/thread_data.h>

static struct wasmux_thread_data s_main_thread_data = { 0 };

#if WASMUX_THREADS
static __THREAD_LOCAL struct wasmux_thread_data* s_thread_data = &s_main_thread_data;
#else
# define s_thread_data &s_main_thread_data
#endif

struct wasmux_thread_data* __get_thread_data()
{
  return s_thread_data;
}
