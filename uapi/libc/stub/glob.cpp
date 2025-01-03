/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "glob.h"

#include <kernel/assert.h>

int glob(const char* pattern, int flags, int (*errcb)(const char* epath, int eerrno), glob_t* glob)
{
  WA_UNREACHABLE();
  return -1;
}

void globfree(glob_t* glob)
{
  WA_UNREACHABLE();
}
