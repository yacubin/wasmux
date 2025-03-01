/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_BYTEORDER_H
#define _WA_KERNEL_BYTEORDER_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t htonl(uint32_t host);
uint16_t htons(uint16_t host);
uint32_t ntohl(uint32_t net);
uint16_t ntohs(uint16_t net);

#ifdef __cplusplus
}
#endif

#endif /* _WA_KERNEL_BYTEORDER_H */
