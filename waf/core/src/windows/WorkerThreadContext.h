/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include "BaseThreadContext.h"

namespace WEI {

class WorkerThreadContext : public BaseThreadContext {
public:
  static WorkerThreadContext* create();
  static void destroy(WorkerThreadContext*);
  static WorkerThreadContext& getInstance();

private:
};

} // namespace WEI
