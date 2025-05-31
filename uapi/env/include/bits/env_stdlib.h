/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_ENV_STDLIB_H
#define _BITS_ENV_STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

char* getenv(const char* name);
int setenv(const char* name, const char* value, int overwrite);
int putenv(char* name);
int unsetenv(const char* name);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_ENV_STDLIB_H */
