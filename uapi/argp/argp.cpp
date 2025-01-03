/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "argp.h"

#include <kernel/compiler.h>
#include <kernel/assert.h>

__ATTR_HIDDEN extern "C"
int __argp_parse(struct argp* argp, int argc, char** argv, unsigned flags, int* index, void* input)
{
  WA_UNREACHABLE();
  return -1;
}

extern "C" __ATTR_ALIAS(__argp_parse, argp_parse) __ATTR_WEAK;
