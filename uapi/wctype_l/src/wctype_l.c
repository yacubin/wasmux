/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wctype.h>

wctype_t wctype_l(const char* name, locale_t locale)
{
  return wctype(name);
}
