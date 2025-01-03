/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "wctype.h"

#include <kernel/assert.h>

wctype_t wctype(const char* name)
{
  WA_UNREACHABLE();
  return 0;
}

int iswctype(wint_t wc, wctype_t charclass)
{
  WA_UNREACHABLE();
  return 0;
}

int iswupper(wint_t wc)
{
  WA_UNREACHABLE();
  return 0;
}

int iswlower(wint_t wc)
{
  WA_UNREACHABLE();
  return 0;
}
