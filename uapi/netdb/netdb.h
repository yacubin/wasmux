/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_NETDB_H
#define _WA_LIBC_NETDB_H

#include <kernel/types.h>
#include <kernel/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AI_PASSIVE 1

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

#define NI_NUMERICHOST 1  // Return the numeric form of the host address
#define NI_NUMERICSERV 2  // Return the numeric form of the service

struct servent {
  char* s_name;
  char** s_aliases;
  int s_port;
  char* s_proto;
};

struct hostent {
  char* h_name;
  char** h_aliases;
  int h_addrtype;
  int h_length;
  char** h_addr_list;
#define h_addr h_addr_list[0]
};

extern int h_errno;

struct servent* getservbyname(const char* name, const char* proto);
struct hostent* gethostbyname(const char* name);

struct addrinfo {
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  socklen_t ai_addrlen;
  struct sockaddr *ai_addr;
  char *ai_canonname;
  struct addrinfo *ai_next;
};

// TODO: CONFIG_ENABLE_GETADDRINFO ON
#define EAI_SERVICE -8

int getaddrinfo(const char* node, const char* service,
                const struct addrinfo* hints, struct addrinfo** buf);
void freeaddrinfo(struct addrinfo* buf);
const char* gai_strerror(int error_code);

int getnameinfo(const struct sockaddr* addr, socklen_t addrlen, char* host,
                size_t hostlen, char* serv, size_t servlen, int flags);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_NETDB_H */
