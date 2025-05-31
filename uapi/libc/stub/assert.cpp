/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

#include <wasmux/cxx/Characters.h>

void __assert_fail(const char* assertion, const char* file, int line, const char* function)
{
  write(STDERR_FILENO, file, wasmux::charactersLength(file));
  write(STDERR_FILENO, ":", 1);
  // write(STDERR_FILENO, line); from local buffer[]
  write(STDERR_FILENO, " Assertion failed: ", 19);
  write(STDERR_FILENO, assertion, wasmux::charactersLength(assertion));
  write(STDERR_FILENO, function, wasmux::charactersLength(function));
  write(STDERR_FILENO, "\n", 1);

  abort();
}
