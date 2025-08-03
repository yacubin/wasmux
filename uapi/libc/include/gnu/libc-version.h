/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _GNU_LIBC_VERSION_H
#define _GNU_LIBC_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

const char* gnu_get_libc_release(void);
const char* gnu_get_libc_version(void);

#ifdef __cplusplus
}
#endif

#endif /* _GNU_LIBC_VERSION_H */
