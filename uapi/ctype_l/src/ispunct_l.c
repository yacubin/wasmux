/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <ctype.h>

int ispunct_l(int ch, locale_t locale)
{
  return ispunct(ch);
}
