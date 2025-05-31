/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/bulk-memory.h>
#include <wasmux/web/console.h>
#include <wasmux/web/string.h>
#include <wasmux/cxx/PrintTo.h>
#include <wasmux/cxx/ObjectCast.h>

int WebConsoleWrite(int level, const char* message, unsigned length)
{
  WebString* msg = WebString_create2(message, length);
  int result = WEI_consoleWrite(level, object_idx_cast(msg));
  WebString_destroy(msg);
  return result;
}

struct console_buffer_s {
  char data[128];
  unsigned size;
  WebConsoleLevel level;
};

static inline void console_buffer_flush(struct console_buffer_s* buffer)
{
  if (buffer->size > 0) {
    WebConsoleWrite(buffer->level, buffer->data, buffer->size);
    buffer->size = 0;
  }
}

static void console_buffer_write(void* ptr, const char* data, unsigned size)
{
  struct console_buffer_s* buffer = (struct console_buffer_s*)ptr;

  unsigned new_size = buffer->size + size;
  if (new_size >= sizeof(buffer->data)) {
    console_buffer_flush(buffer);
  }

  if (size > sizeof(buffer->data)) {
    WebConsoleWrite(buffer->level, data, size);
  }
  else {
    kernel_memory_copy(buffer->data + buffer->size, data, size);
    buffer->size += size;
  }
}

int WebConsoleVPrint(const char* fmt, va_list args)
{
  struct console_buffer_s buffer;
  buffer.size = 0;
  buffer.level = WEB_CONSOLE_DEFAULT;

  if (*fmt == '\001') {
    fmt++;
    char c = *fmt++;
    if ('0' <= c && c <= '9') {
      switch (c - '0')	{
      case WEB_CONSOLE_INFO:
        buffer.level = WEB_CONSOLE_INFO;
        break;
      case WEB_CONSOLE_WARN:
        buffer.level = WEB_CONSOLE_WARN;
        break;
      case WEB_CONSOLE_ERROR:
        buffer.level = WEB_CONSOLE_ERROR;
        break;
      case WEB_CONSOLE_DEBUG:
        buffer.level = WEB_CONSOLE_DEBUG;
        break;
      }
    }
	}

  int ret = wasmux::printTo(&console_buffer_write, &buffer, fmt, args);
  console_buffer_flush(&buffer);

  return ret;
}

int WebConsolePrint(const char* fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  int n = WebConsoleVPrint(fmt, args);
  va_end(args);
  return n;
}
