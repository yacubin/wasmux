/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_NULLPTR_H
#define _WA_KERNEL_NULLPTR_H

#ifdef __cplusplus
using nullptr_t = decltype(nullptr);
#else
typedef void* nullptr_t;
#endif

#ifndef NULL
# ifdef __cplusplus
#  define NULL nullptr
# else
#  define NULL ((void*)0)
# endif
#endif

#endif /* _WA_KERNEL_NULLPTR_H */
