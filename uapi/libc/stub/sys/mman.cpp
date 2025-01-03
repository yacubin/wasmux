/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/mman.h"

#include <kernel/assert.h>
#include <errno.h>

void* mmap(void* addr, size_t size, int prot, int flags, int fd, off_t offset)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int munmap(void* addr, size_t size)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int mprotect(void* addr, size_t size, int prot)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int mlock(const void* addr, size_t size)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int munlock(const void* addr, size_t size)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
