/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_MNTENT_H
#define _WA_LIBC_MNTENT_H

#include <bits/file_struct.h>
#include <paths.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MOUNTED _PATH_MOUNTED

struct mntent {
  char* mnt_fsname;
  char* mnt_dir;
  char* mnt_type;
  char*mnt_opts;
  int  mnt_freq;
  int mnt_passno;
};

struct mntent* getmntent(FILE* f);
struct mntent* getmntent_r(FILE* f, struct mntent* mntbuf, char* buf, int buflen);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_MNTENT_H */
