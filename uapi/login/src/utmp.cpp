/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <utmp.h>
#include <assert.h>

void updwtmp(const char* file, const struct utmp* utmp)
{
  assert(0);
}

struct utmp* pututline(const struct utmp* utmp)
{
  assert(0);
  return nullptr;
}

void setutent(void)
{
  assert(0);
}

void endutent(void)
{
  assert(0);
}
