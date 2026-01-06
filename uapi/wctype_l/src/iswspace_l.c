/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

int iswspace_l(wint_t wc, locale_t locale)
{
  return iswspace(wc);
}
