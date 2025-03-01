/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/wei.h>

namespace WEI {

class Looper {
public:
  void run();
  bool call(WEI_PerformCallback* dispatchCallback, void* userdata);

private:
};

void currentLooperRun();
bool currentLooperCall(WEI_PerformCallback* dispatchCallback, void* userdata);

} // namespace WEI
