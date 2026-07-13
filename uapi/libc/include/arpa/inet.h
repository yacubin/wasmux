/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
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
in_addr_t inet_network(const char* addr);
int inet_aton(const char* addr, struct in_addr* in);

struct in_addr inet_makeaddr(in_addr_t net, in_addr_t host);
in_addr_t inet_lnaof(struct in_addr in);

#ifdef __cplusplus
}
#endif

#endif /* _ARPA_INET_H */
