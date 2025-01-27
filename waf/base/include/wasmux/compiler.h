/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_COMPILER_H
#define _WASMUX_COMPILER_H

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
#define __ATTR_HIDDEN __attribute__((__visibility__("hidden")))
#define __ATTR_PRINTF(fmt, args) __attribute__((__format__(printf, fmt, args)))
#define __ATTR_NORETURN __attribute__((__noreturn__))

#define __LIKELY(x)   __builtin_expect(!!(x), 1)
#define __UNLIKELY(x) __builtin_expect(!!(x), 0)

#endif /* _WASMUX_COMPILER_H */
