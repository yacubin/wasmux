/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/web/string.h>
#include <wasmux/cxx/Characters.h>

WebString* WebString_create(const char* str)
{
  return WebString_create2(str, static_cast<unsigned>(wasmux::charactersLength(str)));
}

WebString* WebString_create2(const char* str, unsigned len)
{
  WEI_Object strObj;

  if (len < WEI_WEBCALL_NARGS * sizeof(unsigned)) {
    unsigned args[WEI_WEBCALL_NARGS]{ len, 0, 0, 0, 0, 0 };
    unsigned index = 0;
    unsigned shift = 8;
    const char* ptr = str;
    const char* end = str + len;
    while (ptr < end) {
      args[index] |= *ptr++ << shift;
      shift += 8;
      if (shift >= 32) {
        shift = 0;
        index++;
      }
    }
    strObj = WEI_stringCreateByArgs(args[0], args[1], args[2], args[3], args[4], args[5]);
  }
  else {
    strObj = WEI_stringCreate(WEI_KERNEL_MEMORY_ID, str, len);
  }

  return reinterpret_cast<WebString*>(strObj);
}

void WebString_destroy(WebString* thiz)
{
  WEI_objectRelease(wobject_idx(thiz));
}

WebString* WebString_clone(WebString* thiz)
{
  WEI_Object strObj;
  strObj = WEI_objectRetain(wobject_idx(thiz));
  return reinterpret_cast<WebString*>(strObj);
}
