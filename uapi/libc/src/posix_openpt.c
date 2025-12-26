/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <fcntl.h>
#include <paths.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

__EXPORT __ATTR_HIDDEN
int __posix_openpt(int flags)
{
  return open(_PATH_DEV "ptmx", flags);
}

__EXPORT __ATTR_WEAK_ALIAS(__posix_openpt, posix_openpt);
