/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <wasmux/thread_data.h>

static struct wax_thread_data s_main_thread_data = { 0 };

#if CONFIG_ENABLE_TLS // TODO: CONFIG_ENABLE_THREADS
static thread_local auto s_thread_data = &s_main_thread_data;
#else
# define s_thread_data &s_main_thread_data
#endif

struct wax_thread_data* __get_thread_data()
{
  return s_thread_data;
}
