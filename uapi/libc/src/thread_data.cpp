/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <bits/thread_data.h>

static struct libc_thread_data s_main_thread_data = { 0 };

#if WASMUX_THREADS
static thread_local auto s_thread_data = &s_main_thread_data;
#else
# define s_thread_data &s_main_thread_data
#endif

struct libc_thread_data* __get_thread_data()
{
  return s_thread_data;
}
