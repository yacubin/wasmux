/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <ctype.h>

int isdigit_l(int ch, locale_t locale)
{
  return isdigit(ch);
}
