/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

#include <wasmux/cxx/Characters.h>

void __assert_fail(const char* assertion, const char* file, int line, const char* function)
{
  write(STDERR_FILENO, file, WAF::charactersLength(file));
  write(STDERR_FILENO, ":", 1);
  // write(STDERR_FILENO, line); from local buffer[]
  write(STDERR_FILENO, " Assertion failed: ", 19);
  write(STDERR_FILENO, assertion, WAF::charactersLength(assertion));
  write(STDERR_FILENO, function, WAF::charactersLength(function));
  write(STDERR_FILENO, "\n", 1);

  abort();
}
