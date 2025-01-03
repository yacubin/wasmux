/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/assert.h>

__attribute__((visibility("hidden")))
extern "C" void wacore_dump()
{
  WA_UNREACHABLE();
}
