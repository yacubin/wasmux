/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <syslog.h>
#include <assert.h>

void openlog(const char* ident, int option, int facility)
{
  assert(0);
}

void closelog(void)
{
  assert(0);
}

int setlogmask(int mask)
{
  assert(0);
  return -1;
}

void syslog(int priority, const char* format, ...)
{
  assert(0);
}

void vsyslog(int priority, const char* message, va_list args)
{
  assert(0);
}
