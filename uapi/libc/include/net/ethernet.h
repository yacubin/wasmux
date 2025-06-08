/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _NET_ETHERNET_H
#define _NET_ETHERNET_H

#include <wasmux/if.h>

#define IF_NAMESIZE IFNAMSIZ

unsigned if_nametoindex(const char* name);
char* if_indextoname(unsigned index, char* buf);

#endif /* _NET_ETHERNET_H */
