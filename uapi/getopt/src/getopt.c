/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <getopt.h>
#include <stddef.h> // for NULL
#include <assert.h>

int optind = 1;
char* optarg = NULL;
int opterr = 0;
int optopt = 0;

int getopt(int argc, char* const* argv, const char* optstring)
{
  assert(0);
  return -1;
}

int getopt_long(int argc, char* const* argv, const char* optstring, const struct option* longopts, int* longindex)
{
  assert(0);
  return -1;
}

int getopt_long_only(int argc, char* const* argv, const char* optstring, const struct option* longopts, int* longindex)
{
  assert(0);
  return -1;
}
