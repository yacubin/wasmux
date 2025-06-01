/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <dirent.h>

__ATTR_HIDDEN
extern "C" int __dirfd(DIR* dir)
{
  return dir->fd;
}

extern "C" __ATTR_ALIAS(__dirfd, dirfd) __ATTR_WEAK;
