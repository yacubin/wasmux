/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_PARAM_H
#define _WA_LIBC_SYS_PARAM_H

#include <wasmux/limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAXPATHLEN PATH_MAX
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_PARAM_H */
