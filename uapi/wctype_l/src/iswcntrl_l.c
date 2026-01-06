/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

int iswcntrl_l(wint_t wc, locale_t locale)
{
  return iswcntrl(wc);
}
