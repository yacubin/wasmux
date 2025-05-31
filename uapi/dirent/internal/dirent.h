/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _INTERNAL_DIRENT_H
#define _INTERNAL_DIRENT_H

#include_next <dirent.h>

struct __dir_struct {
  int fd;
};

#endif /* _INTERNAL_DIRENT_H */
