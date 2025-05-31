/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>
#include <strings.h>
#include <wasmux/assert.h>
#include <wasmux/cxx/MemoryUtils.h>
#include <wasmux/cxx/Characters.h>

int memcmp(const void* p1, const void* p2, size_t n)
{
  return wasmux::memoryCompare(p1, p2, n);
}

void* memmove(void* dst, const void* src, size_t n)
{
  WA_UNREACHABLE();
  return nullptr;
}

char* strchr(const char* str, int ch)
{
  return const_cast<char*>(wasmux::charactersFind<char,true>(str, ch));
}

size_t strlen(const char* str)
{
  return wasmux::charactersLength(str);
}

size_t strnlen(const char* str, size_t len)
{
  return wasmux::charactersLength(str, len);
}

char* strcpy(char* dst, const char* src)
{
  return wasmux::charactersCopy(dst, src);
}

char* strncpy(char* dst, const char* src, size_t n)
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

char* strsignal(int sig)
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
