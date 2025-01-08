/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "dirent.h"

#include <wasmux/assert.h>
#include <errno.h>

struct dirent* readdir(DIR* dir)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

DIR* opendir(const char* path)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int closedir(DIR* dir)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

void rewinddir(DIR* dir)
{
  WA_UNREACHABLE();
}

long telldir(DIR* dir)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

void seekdir(DIR* dir, long offset)
{
  WA_UNREACHABLE();
}

DIR* fdopendir(int fd)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int scandir(const char* dirname, struct dirent*** namelist,
            int (*filter)(const struct dirent*),
            int (*compar)(const struct dirent**, const struct dirent**))
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int versionsort(const struct dirent** a, const struct dirent** b)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
