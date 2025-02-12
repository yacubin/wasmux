/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/stat.h>
#include <fcntl.h>

int stat(const char* path, struct stat* buf)
{
  return fstatat(AT_FDCWD, path, buf, 0);
}
