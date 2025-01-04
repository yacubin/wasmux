/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <utmpx.h>

#include <kernel/assert.h>

struct utmpx* getutxent(void)
{
  WA_UNREACHABLE();
  return nullptr;
}

void setutxent(void)
{
  WA_UNREACHABLE();
}

void endutxent(void)
{
  WA_UNREACHABLE();
}
