/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_STDDEF_H
#define _WA_LIBC_STDDEF_H

#include <kernel/types.h>

#define offsetof(type, member) __builtin_offsetof(type, member)

#endif /* _WA_LIBC_STDDEF_H */
