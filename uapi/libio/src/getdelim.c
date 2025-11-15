/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdio.h>
#include <errno.h>
#include <assert.h>

ssize_t getline(char** line, size_t* n, FILE* file)
{
  return getdelim(line, n, '\n', file);
}
