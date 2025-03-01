/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_SIZEOF_H
#define _WA_KERNEL_SIZEOF_H

#ifndef __SIZEOF_LONG__
# if defined(__wasm64__) || defined(__LP64__)
#  define __SIZEOF_LONG__ 8
#else
#  define __SIZEOF_LONG__ 4
# endif
#endif

#ifndef __SIZEOF_VOIDP__
# define __SIZEOF_VOIDP__ __SIZEOF_LONG__
#endif

#endif /* _WA_KERNEL_SIZEOF_H */
