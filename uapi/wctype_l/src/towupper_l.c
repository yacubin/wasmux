/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

wint_t towupper_l(wint_t wc, locale_t locale)
{
  return towupper(wc);
}
