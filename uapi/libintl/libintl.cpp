/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "libintl.h"

#include <wasmux/assert.h>

char* gettext(const char* msgid)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* dgettext(const char* domainname, const char* msgid)
{
  WA_UNREACHABLE();
  return nullptr;
}
