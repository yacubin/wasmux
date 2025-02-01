/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _MNTENT_H
#define _MNTENT_H

#include <bits/file_struct.h>
#include <paths.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MOUNTED _PATH_MOUNTED

#define MNTTYPE_SWAP "swap"

struct mntent {
  char* mnt_fsname;
  char* mnt_dir;
  char* mnt_type;
  char* mnt_opts;
  int   mnt_freq;
  int   mnt_passno;
};

FILE* setmntent(const char* filename, const char* mode);
int endmntent(FILE* file);
struct mntent* getmntent(FILE* file);
struct mntent* getmntent_r(FILE* file, struct mntent* mntbuf, char* buf, int buflen);
char* hasmntopt(const struct mntent* mnt, const char* opt);

#ifdef __cplusplus
}
#endif

#endif /* _MNTENT_H */
