/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "regex.h"

#include <kernel/assert.h>

int regcomp(regex_t* regex, const char* pattern, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

int regexec(const regex_t* regex, const char* str, size_t match_count, regmatch_t* match, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

size_t regerror(int errcode, const regex_t* regex, char* buf, size_t len)
{
  WA_UNREACHABLE();
  return 0;
}

void regfree(regex_t* regex)
{
  WA_UNREACHABLE();
}
