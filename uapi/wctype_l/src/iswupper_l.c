/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

int iswupper_l(wint_t wc, locale_t locale)
{
  return iswupper(wc);
}
