/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wctype.h>

int iswblank_l(wint_t wc, locale_t locale)
{
  return iswblank(wc);
}
