/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <kernel/sprintf.h>

#include <kernel/bulk-memory.h>
#include <waf/PrintTo.h>

struct sprintf_data_s {
  char* start;
  char* curr;
};

struct snprintf_data_s {
  char* start;
  char* curr;
  char* end;
};

static void sprintf_null_write(void* ptr, const char* str, unsigned len)
{
  struct sprintf_data_s* data = (struct sprintf_data_s*)ptr;

  data->curr += len;
}

static void sprintf_write(void* ptr, const char* str, unsigned len)
{
  struct sprintf_data_s* data = (struct sprintf_data_s*)ptr;

  kernel_memory_copy(data->curr, str, len);
  data->curr += len;
}

static void snprintf_write(void* ptr, const char* str, unsigned len)
{
  struct snprintf_data_s* data = (struct snprintf_data_s*)ptr;

  size_t rem_length = data->end - data->curr;
  if (rem_length < len) {
    len = rem_length;
  }

  kernel_memory_copy(data->curr, str, len);
  data->curr += len;
}

int __kernel_sprintf(char* buf, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  int n = __kernel_vsprintf(buf, fmt, args);
  va_end(args);
  return n;
}

int __kernel_vsprintf(char* buf, const char* fmt, va_list args)
{
  struct sprintf_data_s data = {
    .start = buf,
    .curr = buf,
  };

  int ret = WAF::printTo(buf ? &sprintf_write : &sprintf_null_write, &data, fmt, args);
  *data.curr = '\0';

  return ret;
}

int __kernel_snprintf(char* buf, size_t size, const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  int n = __kernel_vsnprintf(buf, size, fmt, args);
  va_end(args);
  return n;
}

int __kernel_vsnprintf(char* buf, size_t size, const char* fmt, va_list args)
{
  struct snprintf_data_s data = {
    .start = buf,
    .curr = buf,
    .end = buf + size,
  };

  int ret = WAF::printTo(buf ? &snprintf_write : &sprintf_null_write, &data, fmt, args);
  if (data.curr < data.end) {
    *data.curr = '\0';
  }
  
  return ret;
}
