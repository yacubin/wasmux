/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include "MainThreadContext.h"

namespace WEI {

static MainThreadContext s_mainInstance;

MainThreadContext& MainThreadContext::getInstance()
{
  return s_mainInstance;
}

} // namespace WEI
