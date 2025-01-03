/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_GETOPT_CORE_H
#define _WA_LIBC_GETOPT_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

extern int optind;
extern char* optarg;
extern int opterr;
extern int optopt;

int getopt(int argc, char* const* argv, const char* optstring);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_GETOPT_CORE_H */
