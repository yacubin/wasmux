/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_REGEX_H
#define _WA_LIBC_REGEX_H

#include <kernel/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define REG_EXTENDED (1 << 0)
#define REG_ICASE    (1 << 1)
#define REG_NEWLINE  (1 << 2)
#define REG_NOSUB    (1 << 3)

typedef struct {
  size_t re_nsub;
} regex_t;

typedef off_t regoff_t;

typedef struct {
  regoff_t rm_so;
  regoff_t rm_eo;
} regmatch_t;

int regcomp(regex_t* regex, const char* pattern, int flags);
int regexec(const regex_t* regex, const char* str, size_t match_count, regmatch_t* match, int flags);
size_t regerror(int errcode, const regex_t* regex, char* buf, size_t len);
void regfree(regex_t* regex);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_REGEX_H */
