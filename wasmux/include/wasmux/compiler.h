/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_COMPILER_H
#define _WASMUX_COMPILER_H

#include <wasmux/platform.h>

#ifndef __has_builtin
# define __has_builtin(x) 0
#endif

#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#ifndef __STRINGIFY
# define ___STRINGIFY(x) #x
# define __STRINGIFY(x) ___STRINGIFY(x)
#endif

#define ___TOKEN_CONCAT(a,b) a ## b
#define __TOKEN_CONCAT(a,b) ___TOKEN_CONCAT(a,b)

#define __ATTR_ALIAS(from, to) __typeof(from) to __attribute__((__alias__(#from)))

#define __ATTR_WEAK __attribute__((__weak__))
#define __ATTR_WEAK_ALIAS(from, to) __typeof(from) to __attribute__((__weak__, __alias__(#from)))

#ifndef WA_OS_WINDOWS
# define __ATTR_HIDDEN __attribute__((__visibility__("hidden")))
#else
# define __ATTR_HIDDEN
#endif

#define __ATTR_PRINTF(fmt, args) __attribute__((__format__(printf, fmt, args)))
#define __ATTR_NORETURN __attribute__((__noreturn__))
#define __ATTR_USED __attribute__((used))

#ifdef __wasm__
#define __ATTR_EXPORT_NAME(name) __attribute__((export_name(name)))
#define __ATTR_IMPORT_NAME(module, name) __attribute__((import_module(module), import_name(name)))
#else
#define __ATTR_EXPORT_NAME(name)
#define __ATTR_IMPORT_NAME(module, name)
#endif

#define __LIKELY(x)   __builtin_expect(!!(x), 1)
#define __UNLIKELY(x) __builtin_expect(!!(x), 0)

#define __ATTR_ALWAYS_INLINE inline __attribute__((__always_inline__))

#endif /* _WASMUX_COMPILER_H */
