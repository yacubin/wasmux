/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>

int __ATTR_WEAK memcmp(const void* p1, const void* p2, size_t n)
{
  const unsigned char* ptr1 = (const unsigned char*)p1;
  const unsigned char* ptr2 = (const unsigned char*)p2;
  while (n != 0) {
    int a = *ptr1;
    int b = *ptr2;
    int diff = a - b;
    if (diff)
      return diff;
    ptr1++;
    ptr2++;
    n--;
  }
  return 0;
}
