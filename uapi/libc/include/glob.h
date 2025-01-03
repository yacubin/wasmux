/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_GLOB_H
#define _WA_LIBC_GLOB_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define	GLOB_NOSPACE 1
#define	GLOB_ABORTED 2
#define	GLOB_NOMATCH 3
#define GLOB_NOSYS   4

typedef struct {
  size_t gl_pathc;
  char** gl_pathv;
  size_t gl_offs;
} glob_t;

int glob(const char* pattern, int flags, int (*errcb)(const char* epath, int eerrno), glob_t* glob);
void globfree(glob_t* glob);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_GLOB_H */
