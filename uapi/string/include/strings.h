/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _STRINGS_H
#define _STRINGS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int ffs(int i);

void bcopy(const void* src, void* dst, size_t len);
char* rindex(const char* str, int ch);

int strcasecmp(const char* str1, const char* str2);
int strncasecmp(const char* str1, const char* str2, size_t len);

#ifdef __cplusplus
}
#endif

#endif /* _STRINGS_H */
