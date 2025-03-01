/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _NETDB_H
#define _NETDB_H

#include <wasmux/types.h>
#include <wasmux/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AI_PASSIVE     0x0001  /* Socket address for binding (server-side) */
#define AI_CANONNAME   0x0002  /* Request for canonical name */
#define AI_NUMERICHOST 0x0004  /* Prevent hostname resolution, only allow numeric IP */

#define EAI_BADFLAGS    -1   /* Invalid value for `ai_flags` */
#define EAI_NONAME      -2   /* Name or service is not known */
#define EAI_AGAIN       -3   /* Temporary failure in name resolution, try again */
#define EAI_FAIL        -4   /* A non-recoverable error occurred */
#define EAI_FAMILY      -6   /* The requested address family is not supported */
#define EAI_SOCKTYPE    -7   /* The requested socket type is not supported */
#define EAI_MEMORY      -10  /* Memory allocation failure */
#define EAI_SYSTEM      -11  /* A system error occurred (check `errno`) */

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

struct servent* getservbyport(int port, const char* proto);

#ifdef __cplusplus
}
#endif

#endif /* _NETDB_H */
