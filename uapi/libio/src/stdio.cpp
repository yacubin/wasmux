/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <stdio.h>

static struct __file_struct s_std_files[] =
{
  {
    .fd = STDIN_FILENO,
  },
  {
    .fd = STDOUT_FILENO,
  },
  {
    .fd = STDERR_FILENO,
  },
};

#undef stdin
#undef stdout
#undef stderr

FILE* const stdin  = &s_std_files[STDIN_FILENO];
FILE* const stdout = &s_std_files[STDOUT_FILENO];
FILE* const stderr = &s_std_files[STDERR_FILENO];
