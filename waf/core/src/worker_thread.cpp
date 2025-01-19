/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/worker_thread.h>

unsigned WebGetCurrentWorkerId()
{
  WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  if (instance == WebGetMainInstance())
    return WEI_UNDEFINED_OBJECT;
  return instance->worker;
}
