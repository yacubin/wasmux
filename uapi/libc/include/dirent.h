/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_DIRENT_H
#define _WA_LIBC_DIRENT_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DT_UNKNOWN 0
#define DT_FIFO    1
#define DT_CHR     2
#define DT_DIR     4
#define DT_BLK     6
#define DT_REG     8
#define DT_LNK     10
#define DT_SOCK    12
#define DT_WHT     14

typedef struct DIR DIR;
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

int scandir(const char* dirname, struct dirent*** namelist,
            int (*filter)(const struct dirent*),
            int (*compar)(const struct dirent**, const struct dirent**));

int versionsort(const struct dirent** a, const struct dirent** b);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_DIRENT_H */
