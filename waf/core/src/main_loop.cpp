/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/main_loop.h>
#include <wasmux/notify_waiter.h>
#include <wasmux/worker_instance.h>

struct DispatchSyncData {
  WEI_PerformCallback* dispatchCallback;
  void* userdata;
  notify_waiter_t signal;
};

static void dispatchSyncHandler(void* ptr)
{
  auto dsd = reinterpret_cast<DispatchSyncData*>(ptr);
  dsd->dispatchCallback(dsd->userdata);
  (void)notify_waiter_notify(&dsd->signal);
}

int WebMainLoopDispatch(WEI_PerformCallback* dispatchCallback, void* userdata, unsigned flags)
{
  if (!dispatchCallback)
    return -1;

  if (flags & LP_SYNC) {
    if (WebIsMainInstance()) {
      dispatchCallback(userdata);
    }
    else {
      DispatchSyncData dsd = {
        .dispatchCallback = dispatchCallback,
        .userdata = userdata,
        .signal = NOTIFY_WAITER_INIT,
      };
      (void)WEI_postMessage(dispatchSyncHandler, &dsd);
      (void)notify_waiter_wait(&dsd.signal, NOTIFY_WAITER_INFINITE);
    }

    return 0;
  }

  return WEI_postMessage(dispatchCallback, userdata);
}
