/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "errno.h"

char* program_invocation_name = nullptr;
char* program_invocation_short_name = nullptr;

const char* getprogname(void)
{
  return program_invocation_short_name;
}

void setprogname(const char* progname)
{
  program_invocation_short_name = const_cast<char*>(progname);
}
