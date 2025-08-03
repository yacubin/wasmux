/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wctype.h>

int iswlower_l(wint_t wc, locale_t locale)
{
  return iswlower(wc);
}
