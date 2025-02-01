/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _GLOB_H
#define _GLOB_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GLOB_NOSORT      (1 << 2)
#define GLOB_APPEND      (1 << 5)
#define GLOB_NOESCAPE    (1 << 6)
#define GLOB_ALTDIRFUNC  (1 << 9)

#define	GLOB_NOSPACE 1
#define	GLOB_ABORTED 2
#define	GLOB_NOMATCH 3
#define GLOB_NOSYS   4

struct __glibc_glob_struct {
  size_t gl_pathc;
  char** gl_pathv;
  size_t gl_offs;
  int gl_flags;
  void (*gl_closedir) (void*);
  struct dirent* (*gl_readdir) (void*);
  void* (*gl_opendir) (const char*);
  int (*gl_lstat) (const char*, struct stat*);
  int (*gl_stat) (const char*, struct stat*);
};

typedef struct __glibc_glob_struct glob_t;

int glob(const char* pattern, int flags, int (*errcb)(const char* epath, int eerrno), glob_t* glob);
void globfree(glob_t* glob);

#ifdef __cplusplus
}
#endif

#endif /* _GLOB_H */
