/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _ARPA_INET_H
#define _ARPA_INET_H

#include <netinet/in.h>

#ifdef __cplusplus
extern "C" {
#endif

char* inet_ntoa(struct in_addr in);
const char* inet_ntop(int af, const void* addr, char* buf, socklen_t len);
int inet_pton(int af, const char* src, void* dst);

in_addr_t inet_addr(const char* addr);

#ifdef __cplusplus
}
#endif

#endif /* _ARPA_INET_H */
