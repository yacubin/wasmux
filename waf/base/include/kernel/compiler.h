/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_COMPILER_H
#define _WA_KERNEL_COMPILER_H

#ifndef __has_builtin
# define __has_builtin(x) 0
#endif

#ifndef __STRINGIFY
# define ___STRINGIFY(x) #x
# define __STRINGIFY(x) ___STRINGIFY(x)
#endif

#define ___TOKEN_CONCAT(a,b) a ## b
#define __TOKEN_CONCAT(a,b) ___TOKEN_CONCAT(a,b)

#define __ATTR_ALIAS(from, to) __typeof(from) to __attribute__((__alias__(#from)))
#define __ATTR_WEAK __attribute__((__weak__))
#define __ATTR_HIDDEN __attribute__((visibility("hidden")))
#define __ATTR_PRINTF(fmt, args) __attribute__((__format__(printf, fmt, args)))

#endif /* _WA_KERNEL_COMPILER_H */
