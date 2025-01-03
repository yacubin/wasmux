/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_FNMATCH_H
#define _WA_LIBC_FNMATCH_H

#ifdef __cplusplus
extern "C" {
#endif

#define FNM_PATHNAME    (1 << 0)
#define FNM_NOESCAPE    (1 << 1)
#define FNM_PERIOD      (1 << 2)
#define FNM_LEADING_DIR (1 << 3)
#define FNM_CASEFOLD    (1 << 4)
#define FNM_EXTMATCH    (1 << 5)

#define FNM_FILE_NAME   FNM_PATHNAME

#define FNM_NOMATCH     1
#define FNM_NOSYS       (-1)

int fnmatch(const char* pattern, const char* str, int flags);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_FNMATCH_H */
