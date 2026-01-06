/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <glob.h>
#include <assert.h>

int glob(const char* pattern, int flags, int (*errcb)(const char* epath, int eerrno), glob_t* glob)
{
  assert(0);
  return -1;
}

void globfree(glob_t* glob)
{
  assert(0);
}
