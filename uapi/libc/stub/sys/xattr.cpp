/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/xattr.h>
#include <wasmux/assert.h>

ssize_t fgetxattr(int fd, const char* name, void* value, size_t size)
{
  WA_UNREACHABLE();
  return -1;
}

int fsetxattr(int fd, const char* name, const void* value, size_t size, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t flistxattr(int fd, char* list, size_t size)
{
  WA_UNREACHABLE();
  return -1;
}

int fremovexattr(int fd, const char* name)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t getxattr(const char* path, const char* name, void* value, size_t size)
{
  WA_UNREACHABLE();
  return -1;
}

int setxattr(const char* path, const char* name, const void* value, size_t size, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t listxattr(const char* path, char* list, size_t size)
{
  WA_UNREACHABLE();
  return -1;
}

int removexattr(const char* path, const char* name)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t lgetxattr(const char* path, const char* name, void* value, size_t size)
{
  WA_UNREACHABLE();
  return -1;
}

int lsetxattr(const char* path, const char* name,  const void* value, size_t size, int flags)
{
  WA_UNREACHABLE();
  return -1;
}

ssize_t llistxattr(const char* path, char* list, size_t size)
{
  WA_UNREACHABLE();
  return -1;
}

int lremovexattr(const char* path, const char* name)
{
  WA_UNREACHABLE();
  return -1;
}
