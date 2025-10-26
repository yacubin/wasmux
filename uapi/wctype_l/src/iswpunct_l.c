/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

int iswpunct_l(wint_t wc, locale_t locale)
{
  return iswpunct(wc);
}
