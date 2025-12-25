/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <ctype.h>

int isxdigit_l(int ch, locale_t locale)
{
  return isxdigit(ch);
}
