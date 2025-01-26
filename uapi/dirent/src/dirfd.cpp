/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <dirent.h>
#include <wasmux/compiler.h>

#include <bits/__dirent_dir_struct.h>

__ATTR_HIDDEN
extern "C" int __dirfd(DIR* dir)
{
  return dir->fd;
}

extern "C" __ATTR_ALIAS(__dirfd, dirfd) __ATTR_WEAK;
