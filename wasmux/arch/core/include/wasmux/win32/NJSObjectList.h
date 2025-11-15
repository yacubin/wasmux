/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/wei.h>
#include "RefPtr.h"
#include "NJSObject.h"

namespace WEI {

class NJSObjectList {
public:
  bool init();
  NJSObject* get(unsigned id);
  unsigned add(const RefPtr<NJSObject>&);

private:
  RefPtr<NJSObject>* m_objects{nullptr};
  unsigned m_length{0};
  unsigned m_capacity{0};
};

} // namespace WEI
