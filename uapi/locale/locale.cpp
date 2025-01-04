/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "locale.h"

#include <kernel/assert.h>

char* setlocale(int category, const char* locale)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct lconv* localeconv(void)
{
  WA_UNREACHABLE();
  return nullptr;
}
