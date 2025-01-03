/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "syslog.h"

#include <kernel/assert.h>

void openlog(const char* ident, int option, int facility)
{
  WA_UNREACHABLE();
}

void syslog(int priority, const char* format, ...)
{
  WA_UNREACHABLE();
}

void closelog(void)
{
  WA_UNREACHABLE();
}
