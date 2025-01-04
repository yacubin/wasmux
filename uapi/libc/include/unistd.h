/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_UNISTD_H
#define _WA_LIBC_UNISTD_H

#include <features.h>
#include <sys/types.h>
#include <getopt_core.h>
#include <kernel/fs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _POSIX_VERSION 200809L

extern char** environ;

#define F_OK 0
#define X_OK 1
#define W_OK 2
#define R_OK 4

int access(const char* path, int mode);
int link(const char* oldpath, const char* newpath);
int unlink(const char* path);
ssize_t readlink(const char* path, char* buf, size_t len);
int symlink(const char* target, const char* path);
int linkat(int olddirfd, const char* oldpath, int newdirfd, const char* newpath, int flags);
int unlinkat(int dirfd, const char* path, int flags);

int dup(int oldfd);
int dup2(int oldfd, int newfd);
int pipe(int fds[2]);
ssize_t read(int fd, void* buf, size_t count);
ssize_t write(int fd, const void* buf, size_t count);
off_t lseek(int fildes, off_t offset, int whence);
int close(int fd);
int fsync(int fd);

int chdir(const char* path);
int rmdir(const char* path);
int fchdir(int fd);
int fchown(int fd, uid_t owner, gid_t group);
int chown(const char* path, uid_t owner, gid_t group);
int lchown(const char* path, uid_t owner, gid_t group);
int truncate(const char* path, off_t length);
int ftruncate(int fd, off_t length);

#define _PC_PIPE_BUF 1  /* Example: Implementation-defined value */

long fpathconf(int fd, int name);
long pathconf(const char* path, int name);

int isatty(int fd);
char* ttyname(int fd);
int ttyname_r(int fd, char* buf, size_t len);

unsigned sleep(unsigned seconds);
unsigned alarm(unsigned seconds);

enum __sysconf_enum {
  _SC_OPEN_MAX ,
  _SC_GETGR_R_SIZE_MAX,
  _SC_GETPW_R_SIZE_MAX,
  _SC_PAGESIZE,
  _SC_PAGE_SIZE = _SC_PAGESIZE,
};

long sysconf(int name);

void _exit(int status) __attribute__((noreturn));

char* getcwd(char* buf, size_t size);
char* crypt(const char* key, const char* salt);

pid_t getpid(void);
pid_t gettid(void);
pid_t getppid(void);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
int setuid(uid_t uid);
int setgid(gid_t gid);
int seteuid(uid_t euid);
int setegid(gid_t egid);
int setpgid(pid_t pid, pid_t pgid);
int setresuid(uid_t ruid, uid_t euid, uid_t suid);
int setresgid(gid_t rgid, gid_t egid, gid_t sgid);
pid_t setsid(void);
pid_t getpgrp(void);
pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd, pid_t pidgrp);

char* getlogin(void);
int getpagesize(void);
int gethostname(char* name, size_t len);
int getgroups(int size, gid_t* list);
int getentropy(void* data, size_t size);

int pause(void);

int brk(void* addr);
void* sbrk(intptr_t inc);

pid_t fork(void);
pid_t vfork(void);

int execl(const char* path, const char* arg, ...);
int execlp(const char* path, const char* arg, ...);
int execv(const char* path, char* const argv[]);
int execvp(const char* path, char* const argv[]);
int execve(const char* path, char* const argv[], char* const envp[]);

long syscall(long number, ...);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_UNISTD_H */
