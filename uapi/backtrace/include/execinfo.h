/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _EXECINFO_H
#define _EXECINFO_H

#ifdef __cplusplus
extern "C" {
#endif

int backtrace(void** arr, int size);
char** backtrace_symbols(void* const* arr, int size);
void backtrace_symbols_fd(void* const* arr, int size, int fd);

#ifdef __cplusplus
}
#endif

#endif /* _EXECINFO_H */
