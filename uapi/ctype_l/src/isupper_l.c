/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <ctype.h>

int isupper_l(int ch, locale_t locale)
{
  return isupper(ch);
}
