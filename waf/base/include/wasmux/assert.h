
/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_ASSERT_H
#define _WA_KERNEL_ASSERT_H

#if __has_builtin(__builtin_trap) || defined(__GNUC__)
# define WA_UNREACHABLE __builtin_trap
#elif __has_builtin(__builtin_unreachable)
# define WA_UNREACHABLE __builtin_unreachable
#elif defined(_MSC_VER)
# define WA_UNREACHABLE __assume(0)
#elif defined(__wasm__)
static inline void unreachable(void)
{
  __asm__("unreachable\n");
}
# define WA_UNREACHABLE unreachable
#else
#error No support for unreachable macro
#endif

#define WA_ASSERT(cond)    \
  do {                  \
    if (!(cond)) {      \
      WA_UNREACHABLE(); \
    }                   \
  } while(0)

#endif /* _WA_KERNEL_ASSERT_H */
