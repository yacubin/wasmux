/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_APRA_INET_H
#define _WA_LIBC_APRA_INET_H

#include <netinet/in.h>

#ifdef __cplusplus
extern "C" {
#endif

char* inet_ntoa(struct in_addr in);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_APRA_INET_H */
