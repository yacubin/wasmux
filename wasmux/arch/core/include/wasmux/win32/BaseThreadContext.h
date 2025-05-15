/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include "NJSObjectList.h"
#include "Looper.h"

namespace WEI {

class BaseThreadContext {
public:
  Looper& looper() { return m_looper; }
  NJSObjectList& objects() { return m_objects; }

  static BaseThreadContext& getInstance();

private:
  Looper m_looper;
  NJSObjectList m_objects;
};

} // namespace WEI
