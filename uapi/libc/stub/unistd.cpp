/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "unistd.h"

#include <wasmux/compiler.h>
#include <wasmux/assert.h>
#include <errno.h>

int fsync(int fd)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int rmdir(const char* path)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fchdir(int fd)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fchown(int fd, uid_t owner, gid_t group)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int chown(const char* path, uid_t owner, gid_t group)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int lchown(const char* path, uid_t owner, gid_t group)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int truncate(const char* path, off_t length)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int ftruncate(int fd, off_t length)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

ssize_t pread(int fd, void* buf, size_t count, off_t offset)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

long fpathconf(int fd, int name)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

long pathconf(const char* path, int name)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

unsigned sleep(unsigned seconds)
{
  WA_UNREACHABLE();
  return 0;
}

unsigned alarm(unsigned seconds)
{
  WA_UNREACHABLE();
  return 0;
}

long sysconf(int name)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

char* crypt(const char* key, const char* salt)
{
  WA_UNREACHABLE();
  return nullptr;
}

pid_t getpid(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

pid_t getppid(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

uid_t getuid(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

uid_t geteuid(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

gid_t getgid(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

gid_t getegid(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setuid(uid_t uid)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setgid(gid_t gid)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int seteuid(uid_t euid)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setegid(gid_t egid)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setpgid(pid_t pid, pid_t pgid)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

pid_t setsid(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

pid_t getpgrp(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

pid_t tcgetpgrp(int fd)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int tcsetpgrp(int fd, pid_t pidgrp)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

char* getlogin(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int getpagesize(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int gethostname(char* name, size_t len)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int getgroups(int size, gid_t* list)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int getentropy(void* data, size_t size)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int pause(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

pid_t fork(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

pid_t vfork(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int execl(const char* path, const char* arg, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int execlp(const char* path, const char* arg, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int execv(const char* path, char* const argv[])
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int execvp(const char* path, char* const argv[])
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

long syscall(long number, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
