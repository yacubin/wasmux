/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

wint_t towlower_l(wint_t wc, locale_t locale)
{
  return towlower(wc);
}
