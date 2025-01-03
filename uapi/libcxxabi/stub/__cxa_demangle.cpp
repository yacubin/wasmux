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
extern "C" char* __cxa_demangle(const char* name, char* buf, size_t* len, int* status)
{
  WA_UNREACHABLE();
  return nullptr;
}
