/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>

char* strchr(const char* str, int ch)
{
  for (;;) {
    unsigned char c = (unsigned char)*str;
    if (c == (unsigned char)ch)
      return (char*)str;
    if (c == '\0')
      break;
    str++;
  }
  return NULL;
}
