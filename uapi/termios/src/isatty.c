/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <termios.h>

#include <wasmux/export.h>
#include <wasmux/compiler.h>

__ATTR_HIDDEN __EXPORT
int __isatty(int fd)
{
  struct termios termios;
  return tcgetattr(fd, &termios) == 0;
}

__EXPORT __ATTR_ALIAS(__isatty, isatty) __ATTR_WEAK;
