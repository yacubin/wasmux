/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_UCONTEXT_H
#define _WA_LIBC_UCONTEXT_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ucontext_t {
  int dummy;
} ucontext_t;

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_UCONTEXT_H */
