/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

int iswgraph_l(wint_t wc, locale_t locale)
{
  return iswgraph(wc);
}
