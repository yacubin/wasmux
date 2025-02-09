/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <wasmux/compiler.h>

int fsync(int fd)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int rmdir(const char* path)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fchdir(int fd)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fchown(int fd, uid_t owner, gid_t group)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int chown(const char* path, uid_t owner, gid_t group)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int lchown(const char* path, uid_t owner, gid_t group)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int truncate(const char* path, off_t length)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int ftruncate(int fd, off_t length)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

ssize_t pread(int fd, void* data, size_t size, off_t offset)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

ssize_t pwrite(int fd, const void* data, size_t size, off_t offset)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

long fpathconf(int fd, int name)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

long pathconf(const char* path, int name)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

unsigned sleep(unsigned seconds)
{
  assert(0);
  return 0;
}

unsigned alarm(unsigned seconds)
{
  assert(0);
  return 0;
}

long sysconf(int name)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

char* crypt(const char* key, const char* salt)
{
  assert(0);
  return nullptr;
}

int setuid(uid_t uid)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int setgid(gid_t gid)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int seteuid(uid_t euid)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int setegid(gid_t egid)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int setpgid(pid_t pid, pid_t pgid)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

pid_t setsid(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

pid_t getpgrp(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

pid_t tcgetpgrp(int fd)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int tcsetpgrp(int fd, pid_t pidgrp)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

char* getlogin(void)
{
  assert(0);
  errno = ENOSYS;
  return nullptr;
}

int getpagesize(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int getgroups(int size, gid_t* list)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int getentropy(void* data, size_t size)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int pause(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

pid_t fork(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

pid_t vfork(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int execl(const char* path, const char* arg, ...)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int execlp(const char* path, const char* arg, ...)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int execv(const char* path, char* const argv[])
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int execvp(const char* path, char* const argv[])
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
