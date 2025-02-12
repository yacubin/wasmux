/*
 *
 *  Copyright (C) 2024-205  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/mman.h>
#include <assert.h>
#include <errno.h>

void* mmap(void* addr, size_t size, int prot, int flags, int fd, off_t offset)
{
  assert(0);
  errno = ENOSYS;
  return nullptr;
}

int munmap(void* addr, size_t size)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int madvise (void* addr, size_t size, int advice)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int mprotect(void* addr, size_t size, int prot)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int mlock(const void* addr, size_t size)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int munlock(const void* addr, size_t size)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void* mremap(void* old_addr, size_t old_size, size_t new_size, int flags, ...)
{
  assert(0);
  errno = ENOSYS;
  return nullptr;
}
