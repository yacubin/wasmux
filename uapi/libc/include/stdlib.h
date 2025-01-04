/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_STDLIB_H
#define _WA_LIBC_STDLIB_H

#include <kernel/widechar.h>
#include <alloca.h>
#include <malloc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EXIT_SUCCESS 0 // successful program termination
#define EXIT_FAILURE 1 // unsuccessful program termination

#define MB_LEN_MAX 4
#define MB_CUR_MAX 2

int system(const char* command);

int atexit(void (*function)(void));
void exit(int status) __attribute__((noreturn));
void abort(void) __attribute__((noreturn));

void qsort(void* base, size_t n, size_t size, int (*compar) (const void*, const void*));
void* bsearch(const void* key, const void* base, size_t n, size_t size, int (*compar)(const void*, const void*));

long strtol(const char* str, char** end, int base);
long long strtoll(const char* str, char** end, int base);
unsigned long strtoul(const char* str, char** end, int base);
unsigned long long strtoull(const char* str, char** end, int base);
float strtof(const char* str, char** end);
double strtod(const char* str, char** end);

int atoi(const char* str);
long atol(const char* str);
double atof(const char* str);
int wctomb(char* str, wchar_t wch);

char* getenv(const char* name);
int setenv(const char* name, const char* value, int overwrite);
int putenv(char* name);
int unsetenv(const char* name);

int mkstemp(char* temp);
char* mktemp(char* pattern);

const char* getprogname(void);
void setprogname(const char* progname);

int abs(int i);

void srand(unsigned seed);
int rand(void);
long int random(void);

int mblen(const char* str, size_t len);
int mbtowc(wchar_t* pwc, const char* str, size_t len);
size_t mbstowcs(wchar_t* dst, const char* src, size_t dstlen);
size_t wcstombs(char* dst, const wchar_t* src, size_t dstlen);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_STDLIB_H */
