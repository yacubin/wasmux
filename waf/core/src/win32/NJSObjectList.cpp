/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <wasmux/win32/NJSObjectList.h>

#include <wasmux/worker_thread.h>
#include <wasmux/cxx/New.h>

#include <wasmux/win32/OSMalloc.h>
#include <wasmux/win32/MainThreadContext.h>
#include <wasmux/win32/WorkerThreadContext.h>

#include <windows.h>

namespace WEI {

bool NJSObjectList::init()
{
  if (m_objects) {
    return false;
  }

  m_length = 16;
  m_capacity = 32;
  m_objects = reinterpret_cast<RefPtr<NJSObject>*>(OSMalloc(m_capacity * sizeof(NJSObject)));

  for (unsigned i = 0; i < m_length; ++i) {
    new (WAF::CtorOnly, &m_objects[i]) RefPtr<NJSObject>;
  }

  m_objects[WEI_KERNEL_MEMORY_ID] = RefPtr<NJSObject>{};
  m_objects[WEI_KERNEL_MODULE_ID] = RefPtr<NJSObject>{};
  m_objects[WEI_USER_WORKER] = RefPtr<NJSObject>{};
  m_objects[WEI_NULL_OBJECT] = RefPtr<NJSObject>{};
  m_objects[WEI_GLOBAL_THIS] = RefPtr<NJSObject>{};
  m_objects[WEI_SCRIPT_URL_ID] = RefPtr<NJSObject>{};

  return true;
}

NJSObject* NJSObjectList::get(unsigned id)
{
  if (id < m_length)
    return m_objects[id].get();
  return nullptr;
}

unsigned NJSObjectList::add(const RefPtr<NJSObject>& object)
{
  if (m_objects) {
    if (m_length < m_capacity) {
      unsigned id = m_length++;
      new (WAF::CtorOnly, &m_objects[id]) RefPtr<NJSObject>(object);
      return id;
    }
  }

  return 0;
}

} // namespace WEI
