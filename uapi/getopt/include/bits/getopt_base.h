/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_GETOPT_BASE_H
#define _BITS_GETOPT_BASE_H

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

#endif /* _BITS_GETOPT_BASE_H */
