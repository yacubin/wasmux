/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <ctype.h>

int islower_l(int ch, locale_t locale)
{
  return islower(ch);
}
