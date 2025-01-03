/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_LIBGEN_H
#define _WA_LIBC_LIBGEN_H

#include <kernel/basename.h>

#ifdef __cplusplus
extern "C" {
#endif

char* dirname(char* path);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_LIBGEN_H */
