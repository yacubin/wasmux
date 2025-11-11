/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <strings.h>
#include <assert.h>
#include <wasmux/cxx/Characters.h>

int memcmp(const void* p1, const void* p2, size_t n)
{
  while (n != 0) {
    int a = *(const uint8_t*)(p1);
    int b = *(const uint8_t*)(p2);
    int diff = a - b;
    if (diff)
      return diff;
    p1 = (const uint8_t*)(p1) + 1;
    p2 = (const uint8_t*)(p2) + 1;
    n--;
  }
  return 0;
}

void* memmove(void* dst, const void* src, size_t n)
{
  assert(0);
  return nullptr;
}

char* strchr(const char* str, int ch)
{
  return const_cast<char*>(wasmux::charactersFind<char,true>(str, ch));
}

size_t strlen(const char* str)
{
  const char* ptr = str;
  while (*ptr)
    ptr++;
  return ptr - str;
}

size_t strnlen(const char* str, size_t len)
{
  size_t n = 0;
  while (n < len && str[n])
    n++;
  return n;
}

char* strtok(char* str, const char* delim)
{
  assert(0);
  return nullptr;
}

char* strcat(char* dst, const char* src)
{
  assert(0);
  return nullptr;
}

char* strncat(char* dst, const char* src, size_t len)
{
  assert(0);
  return nullptr;
}

char* strstr(const char* haystack, const char* needle)
{
  assert(0);
  return nullptr;
}

char* strpbrk(const char* str, const char* accept)
{
  assert(0);
  return nullptr;
}

char* strndup(const char* str, size_t len)
{
  assert(0);
  return nullptr;
}

size_t strspn(const char* str, const char* accept)
{
  assert(0);
  return 0;
}

size_t strcspn(const char* str, const char* reject)
{
  assert(0);
  return 0;
}

size_t strxfrm(char* dst, const char* src, size_t len)
{
  assert(0);
  return 0;
}

int strcoll(const char* s1, const char* s2)
{
  assert(0);
  return 0;
}

char* strsignal(int sig)
{
  assert(0);
  return nullptr;
}

int ffs(int i)
{
  assert(0);
  return 0;
}

void bcopy(const void* src, void* dst, size_t len)
{
  assert(0);
}

int strcasecmp(const char* str1, const char* str2)
{
  assert(0);
  return 0;
}

int strncasecmp(const char* str1, const char* str2, size_t len)
{
  assert(0);
  return 0;
}
