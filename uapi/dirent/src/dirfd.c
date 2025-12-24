/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <dirent.h>
#include <stddef.h> // for NULL
#include <wasmux/compiler.h>

__ATTR_HIDDEN
int __dirfd(DIR* dir)
{
  return dir->fd;
}

__ATTR_ALIAS(__dirfd, dirfd) __ATTR_WEAK;
