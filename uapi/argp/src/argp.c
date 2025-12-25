/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <argp.h>
#include <assert.h>
#include <wasmux/compiler.h>

__ATTR_HIDDEN
int __argp_parse(struct argp* argp, int argc, char** argv, unsigned flags, int* index, void* input)
{
  assert(0);
  return -1;
}

__ATTR_ALIAS(__argp_parse, argp_parse) __ATTR_WEAK;
