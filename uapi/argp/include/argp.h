/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _ARGP_H
#define _ARGP_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct argp {
  int dummy;
};

int argp_parse(struct argp* argp, int argc, char** argv, unsigned flags, int* index, void* input);

#ifdef __cplusplus
}
#endif

#endif /* _ARGP_H */
