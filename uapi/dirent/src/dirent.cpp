/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <dirent.h>
#include <errno.h>
#include <assert.h>

struct dirent* readdir(DIR* dir)
{
  assert(0);
  errno = ENOSYS;
  return nullptr;
}

DIR* opendir(const char* path)
{
  assert(0);
  errno = ENOSYS;
  return nullptr;
}

int closedir(DIR* dir)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void rewinddir(DIR* dir)
{
  assert(0);
}

long telldir(DIR* dir)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void seekdir(DIR* dir, long offset)
{
  assert(0);
}

DIR* fdopendir(int fd)
{
  assert(0);
  errno = ENOSYS;
  return nullptr;
}

int scandir(const char* dirname, struct dirent*** namelist,
            int (*filter)(const struct dirent*),
            int (*compar)(const struct dirent**, const struct dirent**))
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int alphasort(const struct dirent** a, const struct dirent** b)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int versionsort(const struct dirent** a, const struct dirent** b)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

ssize_t getdents(int fd, void* dir_list, size_t count)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
