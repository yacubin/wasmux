/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#undef assert

#ifdef	NDEBUG
#define assert(...) ((void)0)
#else
#define assert(...) ((void)0)
#endif

#ifndef __cplusplus
# undef static_assert
# define static_assert _Static_assert
#endif
