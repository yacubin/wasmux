/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <locale.h>
#include <assert.h>

char* setlocale(int category, const char* locale)
{
  assert(0);
  return nullptr;
}

locale_t newlocale(int category_mask, const char* locale, locale_t base)
{
  assert(0);
  return nullptr;
}

void freelocale(locale_t locale)
{
  assert(0);
}

struct lconv* localeconv(void)
{
  assert(0);
  return nullptr;
}
