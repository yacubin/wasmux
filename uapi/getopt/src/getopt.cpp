/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "getopt.h"

#include <wasmux/assert.h>

int optind = 1;
char* optarg = nullptr;
int opterr = 0;
int optopt = 0;

int getopt(int argc, char* const* argv, const char* optstring)
{
  WA_UNREACHABLE();
  return -1;
}

int getopt_long(int argc, char* const* argv, const char* optstring, const struct option* longopts, int* longindex)
{
  WA_UNREACHABLE();
  return -1;
}

int getopt_long_only(int argc, char* const* argv, const char* optstring, const struct option* longopts, int* longindex)
{
  WA_UNREACHABLE();
  return -1;
}
