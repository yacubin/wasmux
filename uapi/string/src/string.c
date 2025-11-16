/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <strings.h>
#include <assert.h>

void* memmove(void* dst, const void* src, size_t n)
{
  assert(0);
  return NULL;
}

char* strchr(const char* str, int ch)
{
  for (;;) {
    char c = *str;
    if (c == '\0' || c == ch)
      return str;
    str++;
  }
  return NULL;
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
  return NULL;
}

char* strcat(char* dst, const char* src)
{
  assert(0);
  return NULL;
}

char* strncat(char* dst, const char* src, size_t len)
{
  assert(0);
  return NULL;
}

char* strstr(const char* haystack, const char* needle)
{
  assert(0);
  return NULL;
}

char* strpbrk(const char* str, const char* accept)
{
  assert(0);
  return NULL;
}

char* strndup(const char* str, size_t len)
{
  assert(0);
  return NULL;
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
  return NULL;
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
