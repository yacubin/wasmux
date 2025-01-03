/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "mntent.h"

#include <kernel/assert.h>

struct mntent* getmntent(FILE* f)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct mntent* getmntent_r(FILE* f, struct mntent* mntbuf, char* buf, int buflen)
{
  WA_UNREACHABLE();
  return nullptr;
}
