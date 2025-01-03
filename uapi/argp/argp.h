/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_ARGP_ARGP_H
#define _WA_ARGP_ARGP_H

#include <kernel/types.h>

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

#endif /* _WA_ARGP_ARGP_H */
