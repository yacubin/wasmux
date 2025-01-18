/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _STDIO_EXT_H
#define _STDIO_EXT_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t __fpending(FILE* file);
int __freading(FILE* file);
int __fwriting (FILE* file);
void __fpurge(FILE* file);
size_t __freadahead(FILE* file);
const char* __freadptr(FILE* file, size_t* psize);
void __freadptrinc(FILE* file, size_t increment);
void __fseterr(FILE* file);

#ifdef __cplusplus
}
#endif

#endif /* _STDIO_EXT_H */
