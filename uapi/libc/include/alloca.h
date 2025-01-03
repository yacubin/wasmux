/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_ALLOCA_H
#define _WA_LIBC_ALLOCA_H

#ifdef __cplusplus
extern "C" {
#endif

#define alloca(size) __builtin_alloca(size)

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_ALLOCA_H */
