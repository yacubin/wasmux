/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _DIRENT_H
#define _DIRENT_H

#include <sys/types.h>
#include <wasmux/limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAXNAMLEN NAME_MAX

#define DT_UNKNOWN 0
#define DT_FIFO    1
#define DT_CHR     2
#define DT_DIR     4
#define DT_BLK     6
#define DT_REG     8
#define DT_LNK     10
#define DT_SOCK    12
#define DT_WHT     14

typedef struct __dir_struct DIR;

struct dirent {
  ino_t d_ino;
  unsigned short int d_reclen;
  unsigned char d_type;
  unsigned char d_namlen;
  char d_name[1];
};

struct dirent* readdir(DIR* dirp);
DIR* opendir(const char* path);
int closedir(DIR* dir);
void rewinddir(DIR* dir);
long telldir(DIR* dir);
void seekdir(DIR* dir, long offset);
int dirfd(DIR* dir);
DIR* fdopendir(int fd);

int scandir(const char* dirname, struct dirent*** namelist,
            int (*filter)(const struct dirent*),
            int (*compar)(const struct dirent**, const struct dirent**));

int versionsort(const struct dirent** a, const struct dirent** b);
ssize_t getdents(int fd, void* dir_list, size_t count);

#ifdef __cplusplus
}
#endif

#endif /* _DIRENT_H */
