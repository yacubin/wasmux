/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wchar.h>
#include <waf/Characters.h>

wchar_t* wcschr(const wchar_t* wcs, wchar_t wch)
{
  return const_cast<wchar_t*>(WAF::charactersFind<wchar_t,true>(wcs, wch));
}
