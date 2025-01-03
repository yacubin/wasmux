/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "obstack.h"

#include <kernel/compiler.h>
#include <kernel/assert.h>

void _obstack_free(struct obstack* obstack, void* obj)
{
  WA_UNREACHABLE();
}
