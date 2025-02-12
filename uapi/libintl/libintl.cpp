/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <libintl.h>
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

char* dngettext(const char* domainname, const char* msgid, const char* msgid_plural, unsigned long n)
{
  WA_UNREACHABLE();
  return nullptr;
}
