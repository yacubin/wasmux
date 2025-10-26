/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

int iswctype_l(wint_t wc, wctype_t charclass, locale_t locale)
{
  return iswctype(wc, charclass);
}
