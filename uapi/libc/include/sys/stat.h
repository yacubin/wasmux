/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_STAT_H
#define _WA_LIBC_SYS_STAT_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define S_IFMT   0xf000
#define S_IFIFO  0x1000
#define S_IFCHR  0x2000
#define S_IFDIR  0x4000
#define S_IFBLK  0x6000
#define S_IFREG  0x8000
#define S_IFLNK  0xa000
#define S_IFSOCK 0xc000

#define S_ISUID  0x0800
#define S_ISGID  0x0400
#define S_ISVTX  0x0200

#define S_ISFIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define S_ISCHR(mode)  (((mode) & S_IFMT) == S_IFCHR)
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#define S_ISBLK(mode)  (((mode) & S_IFMT) == S_IFBLK)
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#define S_ISLNK(mode)  (((mode) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)

#define S_IXOTH 0001
#define S_IWOTH 0002
#define S_IROTH 0004
#define S_IRWXO 0007

#define S_IXGRP 0010
#define S_IWGRP 0020
#define S_IRGRP 0040
#define S_IRWXG 0070

#define S_IXUSR 0100
#define S_IWUSR 0200
#define S_IRUSR 0400
#define S_IRWXU 0700

#define S_IEXEC  S_IXUSR
#define S_IWRITE S_IWUSR
#define S_IREAD  S_IRUSR

struct stat {
  dev_t     st_dev;         /* ID of device containing file */
  ino_t     st_ino;         /* Inode number */
  mode_t    st_mode;        /* File type and mode (permissions) */
  nlink_t   st_nlink;       /* Number of hard links */
  uid_t     st_uid;         /* User ID of owner */
  gid_t     st_gid;         /* Group ID of owner */
  dev_t     st_rdev;        /* Device ID (if special file) */
  off_t     st_size;        /* Total size, in bytes */
  blksize_t st_blksize;     /* Block size for filesystem I/O */
  blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */

  struct timespec st_atim;  /* Time of last access */
  struct timespec st_mtim;  /* Time of last modification */
  struct timespec st_ctim;  /* Time of last status change */

#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
};

int fstat(int fd, struct stat* buf);
int stat(const char* path, struct stat* buf);
int lstat(const char* path, struct stat* buf);
int fstatat(int dirfd, const char* path, struct stat* buf, int flags);
int mkdir(const char* path, mode_t mode);
int fchmod(int fd, mode_t mode);
int chmod(const char* path, mode_t mode);
int mknod(const char* path, mode_t mode, dev_t dev);
int mkdirat(int dirfd, const char* path, mode_t mode);
int mkfifo(const char* path, mode_t mode);

mode_t umask(mode_t mask);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_STAT_H */
