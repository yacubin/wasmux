/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include "BaseThreadContext.h"

namespace WEI {

class MainThreadContext : public BaseThreadContext {
public:
  static MainThreadContext& getInstance();

private:
};

} // namespace WEI
