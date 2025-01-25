/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "BasicConfig.h"

#include <wasmux/alert.h>
#include <wasmux/cxx/Characters.h>
#include <wasmux/cxx/ObjectCast.h>
#include <wasmux/web/object.h>
#include <wasmux/web/string.h>
#include <wasmux/main_loop.h>

struct alert_params_s {
  const char* msg;
  size_t len;
};

static void WebAlertImpl(void* ptr)
{
  struct alert_params_s* params = (struct alert_params_s*)ptr;
  WebString* str = WebString_create2(params->msg, params->len);
  WebObject_callObjMethod(WEI_GLOBAL_THIS, "alert", object_idx_cast(str), 0, 0, 0);
  WebString_destroy(str);
}

void WebAlert(const char* message)
{
  struct alert_params_s params = {
    .msg = message,
    .len = WAF::charactersLength(message),
  };
  WebMainLoopDispatch(&WebAlertImpl, (void*)&params, LP_SYNC);
}
