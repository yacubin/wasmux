/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_CTYPE_H
#define _WA_LIBC_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

int toupper(int ch);
int tolower(int ch);

int isalpha(int ch);
int isalnum(int ch);
int isalpha(int ch);
int iscntrl(int ch);
int isdigit(int ch);
int isgraph(int ch);
int islower(int ch);
int isprint(int ch);
int ispunct(int ch);
int isspace(int ch);
int isupper(int ch);
int isxdigit(int ch);

int isascii(int ch);
int isblank(int ch);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_CTYPE_H */
