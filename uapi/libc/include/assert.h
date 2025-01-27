/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux/compiler.h>

#undef assert

#ifdef	NDEBUG
#define assert(...) ((void)0)
#else
#define assert(expr) do { \
    if (__UNLIKELY(expr)) { \
      __assert_fail(#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__); \
    } \
  } while (0)

#endif

#ifdef __cplusplus
extern "C" {
#endif

void __assert_fail(const char* assertion, const char* file, int line, const char* function) __ATTR_NORETURN;

#ifdef __cplusplus
}
#endif

#ifndef __cplusplus
# undef static_assert
# define static_assert _Static_assert
#endif
