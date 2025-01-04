/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "string.h"
#include "strings.h"

#include <kernel/assert.h>
#include <waf/Characters.h>

int memcmp(const void* p1, const void* p2, size_t n)
{
  WA_UNREACHABLE();
  return -1;
}

void* memmove(void* dst, const void* src, size_t n)
{
  WA_UNREACHABLE();
  return nullptr;
}

void* memchr(const void* mem, int ch, size_t n)
{
  WA_UNREACHABLE();
  return nullptr;
}

void* memrchr(const void* mem, int ch, size_t n)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strchr(const char* str, int ch)
{
  return const_cast<char*>(WAF::charactersFind<char,true>(str, ch));
}

char* strchrnul(const char* str, int ch)
{
  return const_cast<char*>(WAF::charactersFind<char,false>(str, ch));
}

size_t strlen(const char* str)
{
  return WAF::charactersLength(str);
}

int strcmp(const char* str1, const char* str2)
{
  return WAF::charactersCompare(str1, str2);
}

int strncmp(const char* s1, const char* s2, size_t n)
{
  WA_UNREACHABLE();
  return -1;
}

char* strcpy(char* dst, const char* src)
{
  return WAF::charactersCopy(dst, src);
}

char* strncpy(char* dst, const char* src, size_t n)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strrchr(const char* str, int ch)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strtok(char* str, const char* delim)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strcat(char* dst, const char* src)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strncat(char* dst, const char* src, size_t len)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strstr(const char* haystack, const char* needle)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strpbrk(const char* str, const char* accept)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strdup(const char* str)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strndup(const char* str, size_t len)
{
  WA_UNREACHABLE();
  return nullptr;
}

size_t strspn(const char* str, const char* accept)
{
  WA_UNREACHABLE();
  return 0;
}

size_t strcspn(const char* str, const char* reject)
{
  WA_UNREACHABLE();
  return 0;
}

size_t strxfrm(char* dst, const char* src, size_t len)
{
  WA_UNREACHABLE();
  return 0;
}

int strcoll(const char* s1, const char* s2)
{
  WA_UNREACHABLE();
  return 0;
}

char* strerror(int errnum)
{
  WA_UNREACHABLE();
  return nullptr;
}

int ffs(int i)
{
  WA_UNREACHABLE();
  return 0;
}

void bcopy(const void* src, void* dst, size_t len)
{
  WA_UNREACHABLE();
}

int strcasecmp(const char* str1, const char* str2)
{
  WA_UNREACHABLE();
  return 0;
}

int strncasecmp(const char* str1, const char* str2, size_t len)
{
  WA_UNREACHABLE();
  return 0;
}
