/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei/worker_thread.h>
#include <wasmux/wei.h>

unsigned WebGetCurrentWorkerId()
{
  WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  if (instance == WebGetMainInstance())
    return WEI_UNDEFINED_OBJECT;
  return wobject_idx(instance->worker);
}
