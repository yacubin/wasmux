/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <termios.h>
#include <wasmux/compiler.h>

__ATTR_HIDDEN
extern "C" int __isatty(int fd)
{
  struct termios termios;
  return tcgetattr(fd, &termios) == 0;
}

extern "C" __ATTR_ALIAS(__isatty, isatty) __ATTR_WEAK;
