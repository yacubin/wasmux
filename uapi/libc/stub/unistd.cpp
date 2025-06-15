/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int fsync(int fd)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int rmdir(const char* path)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int fchdir(int fd)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int fchown(int fd, uid_t owner, gid_t group)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int chown(const char* path, uid_t owner, gid_t group)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int lchown(const char* path, uid_t owner, gid_t group)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int truncate(const char* path, off_t length)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int ftruncate(int fd, off_t length)
{
  abort();
  errno = ENOSYS;
  return -1;
}

ssize_t pread(int fd, void* data, size_t size, off_t offset)
{
  abort();
  errno = ENOSYS;
  return -1;
}

ssize_t pwrite(int fd, const void* data, size_t size, off_t offset)
{
  abort();
  errno = ENOSYS;
  return -1;
}

long fpathconf(int fd, int name)
{
  abort();
  errno = ENOSYS;
  return -1;
}

long pathconf(const char* path, int name)
{
  abort();
  errno = ENOSYS;
  return -1;
}

unsigned sleep(unsigned seconds)
{
  abort();
  return 0;
}

unsigned alarm(unsigned seconds)
{
  abort();
  return 0;
}

long sysconf(int name)
{
  abort();
  errno = ENOSYS;
  return -1;
}

char* crypt(const char* key, const char* salt)
{
  abort();
  return nullptr;
}

int setuid(uid_t uid)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int setgid(gid_t gid)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int seteuid(uid_t euid)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int setegid(gid_t egid)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int setpgid(pid_t pid, pid_t pgid)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
  abort();
  errno = ENOSYS;
  return -1;
}

pid_t setsid(void)
{
  abort();
  errno = ENOSYS;
  return -1;
}

char* getlogin(void)
{
  abort();
  errno = ENOSYS;
  return nullptr;
}

int getpagesize(void)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int getgroups(int size, gid_t* list)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int getentropy(void* data, size_t size)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int pause(void)
{
  abort();
  errno = ENOSYS;
  return -1;
}

pid_t fork(void)
{
  abort();
  errno = ENOSYS;
  return -1;
}

pid_t vfork(void)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int execl(const char* path, const char* arg, ...)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int execlp(const char* path, const char* arg, ...)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int execv(const char* path, char* const argv[])
{
  abort();
  errno = ENOSYS;
  return -1;
}

int execvp(const char* path, char* const argv[])
{
  abort();
  errno = ENOSYS;
  return -1;
}
