/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <stdlib.h>
#include <fcntl.h>
#include <paths.h>
#include <wasmux/compiler.h>

__ATTR_HIDDEN
extern "C" int __posix_openpt(int flags)
{
  return open(_PATH_DEV "ptmx", flags);
}

extern "C" __ATTR_ALIAS(__posix_openpt, posix_openpt) __ATTR_WEAK;
