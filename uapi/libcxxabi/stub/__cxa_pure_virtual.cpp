/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/types.h>
#include <kernel/compiler.h>
#include <kernel/assert.h>

__ATTR_HIDDEN
extern "C" void __cxa_pure_virtual()
{
  WA_UNREACHABLE();
}
