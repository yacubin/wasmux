/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_STRING_H
#define _WA_LIBC_STRING_H

#include <strings.h>
#include <kernel/basename.h>

#ifdef __cplusplus
extern "C" {
#endif

void* memcpy(void* dst, const void* src, size_t n);
void* mempcpy(void* dst, const void* src, size_t n);
void* memset(void* mem, int ch, size_t n);

int memcmp(const void* p1, const void* p2, size_t n);
void* memmove(void* dst, const void* src, size_t n);
void* memchr(const void* mem, int ch, size_t n);
void* memrchr(const void* mem, int ch, size_t n);

char* strchr(const char* str, int ch);
char* strchrnul(const char* str, int ch);
size_t strlen(const char* str);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);
char* strcpy(char* dst, const char* src);
char* strncpy(char* dst, const char* src, size_t n);
char* strrchr(const char* str, int ch);
char* strtok(char* str, const char* delim);
char* strcat(char* dst, const char* src);
char* strncat(char* dst, const char* src, size_t len);
char* strstr(const char* haystack, const char* needle);
char* strpbrk(const char* str, const char* accept);
char* strdup(const char* str);
char* strndup(const char* str, size_t len);
size_t strspn(const char* str, const char* accept);
size_t strcspn(const char* str, const char* reject);
size_t strxfrm(char* dst, const char* src, size_t len);
int strcoll(const char* str1, const char* str2);
double strtod(const char* str, char** end);

char* strerror(int errnum);
char* strsignal(int sig);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_STRING_H */
