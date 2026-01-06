/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stddef.h>
#include <errno.h>

char* program_invocation_name = NULL;
char* program_invocation_short_name = NULL;

const char* getprogname(void)
{
  return program_invocation_short_name;
}

void setprogname(const char* progname)
{
  program_invocation_short_name = (char*)progname;
}
