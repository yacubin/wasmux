/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "search.h"

#include <wasmux/assert.h>

void* tsearch(const void* key, void** root, int (*compare)(const void*, const void*))
{
  WA_UNREACHABLE();
  return nullptr;
}

void* tfind(const void* key, void* const* root, int (*compare)(const void*, const void*))
{
  WA_UNREACHABLE();
  return nullptr;
}

void* tdelete(const void* key, void ** root, int (*compare)(const void*, const void*))
{
  WA_UNREACHABLE();
  return nullptr;
}

void twalk(const void* root, void (*action)(const void* node, VISIT which, int depth))
{
  WA_UNREACHABLE();
}
