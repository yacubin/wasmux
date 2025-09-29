/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _STDDEF_H
#define _STDDEF_H

#include <wasmux/types.h>

#define offsetof(type, member) __builtin_offsetof(type, member)

#endif /* _STDDEF_H */
