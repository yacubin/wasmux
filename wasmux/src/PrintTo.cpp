/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/PrintTo.h>
#include <wasmux/cxx/Characters.h>

namespace wasmux {

enum {
  PRINT_FORMAT_NONE,
  PRINT_FORMAT_INT,
  PRINT_FORMAT_UINT,
  PRINT_FORMAT_LONG,
  PRINT_FORMAT_ULONG,
  PRINT_FORMAT_LONGLONG,
  PRINT_FORMAT_ULONGLONG,
  PRINT_FORMAT_STR,
  PRINT_FORMAT_VOIDP,
  PRINT_FORMAT_EOF,
};

static inline char to_hex_lower(char num)
{
  return (num < 10 ? '0' : 'a' - 10) + num;
}

int printTo(PrintCallback* callback, void* ptr, const char* fmt, va_list args)
{
  int type;
  char buffer[32];

  unsigned count = 0;
  unsigned len = 0;
  unsigned fmt_size;

  const char* start = fmt;
  const char* position = fmt;

  for (;;) {
    char c = position[0];
    switch (c) {
    case '\0':
      type = PRINT_FORMAT_EOF;
      fmt_size = 0;
      break;
    case '%':

      c = position[1];
      switch (c) {
      case 'd':
      case 'i':
        type = PRINT_FORMAT_INT;
        fmt_size = 2;
        break;
      case 'u':
        type = PRINT_FORMAT_UINT;
        fmt_size = 2;
        break;
      case 's':
        type = PRINT_FORMAT_STR;
        fmt_size = 2;
        break;
      case 'p':
        type = PRINT_FORMAT_VOIDP;
        fmt_size = 2;
        break;
      case 'l':

        c = position[2];
        switch (c) {
        case 'i':
          type = PRINT_FORMAT_LONG;
          fmt_size = 3;
          break;
        case 'u':
          type = PRINT_FORMAT_ULONG;
          fmt_size = 3;
          break;
        case 'l':

          c = position[3];
          switch (c) {
          case 'i':
            type = PRINT_FORMAT_LONGLONG;
            fmt_size = 4;
            break;
          case 'u':
            type = PRINT_FORMAT_ULONGLONG;
            fmt_size = 4;
            break;
          default:
            type = PRINT_FORMAT_NONE;
            fmt_size = 0;
            break;
          }

          break;
        default:
          type = PRINT_FORMAT_NONE;
          fmt_size = 0;
          break;
        }

        break;
      default:
        type = PRINT_FORMAT_NONE;
        fmt_size = 0;
        break;
      }
      break;
    default:
      type = PRINT_FORMAT_NONE;
      fmt_size = 0;
      break;
    }

    if (type == PRINT_FORMAT_NONE) {
      position++;
      continue;
    }

    len = (unsigned)(position - start);
    if (len) {
      callback(ptr, start, len);
      start = position;
      count += len;
    }

    if (type == PRINT_FORMAT_EOF) {
      break;
    }

    len = 0;
    switch (type) {
    case PRINT_FORMAT_INT: {
      int value = va_arg(args, int);
      char* curr = buffer + sizeof(buffer);
      int sign = value < 0 ? 1 : 0;
      if (sign) {
        value = -value;
      }

      do {
        *--curr = value % 10 + '0';
        value /= 10;
        len++;
      } while (value != 0);

      if (sign) {
        *--curr = '-';
        len++;
      }
      
      callback(ptr, curr, len);
      break;
    }

    case PRINT_FORMAT_UINT: {
      unsigned value = va_arg(args, unsigned);
      char* curr = buffer + sizeof(buffer);

      do {
        *--curr = value % 10 + '0';
        value /= 10;
        len++;
      } while (value != 0);
      
      callback(ptr, curr, len);
      break;
    }

    case PRINT_FORMAT_VOIDP: {
      uintptr_t value = reinterpret_cast<uintptr_t>(va_arg(args, void*));
      char* curr = buffer + sizeof(buffer);

      do {
        *--curr = to_hex_lower(value & 15);
        value >>= 4;
        len++;
      } while (value != 0);

      *--curr = 'x';
      *--curr = '0';
      len += 2;
      
      callback(ptr, curr, len);
      break;
    }

    case PRINT_FORMAT_LONG: {
      long value = va_arg(args, long);
      char* curr = buffer + sizeof(buffer);
      int sign = value < 0 ? 1 : 0;
      if (sign) {
        value = -value;
      }

      do {
        *--curr = value % 10 + '0';
        value /= 10;
        len++;
      } while (value != 0);

      if (sign) {
        *--curr = '-';
        len++;
      }

      callback(ptr, curr, len);
      break;
    }

    case PRINT_FORMAT_LONGLONG: {
      long long value = va_arg(args, long long);
      char* curr = buffer + sizeof(buffer);
      int sign = value < 0 ? 1 : 0;
      if (sign) {
        value = -value;
      }

      do {
        *--curr = value % 10 + '0';
        value /= 10;
        len++;
      } while (value != 0);

      if (sign) {
        *--curr = '-';
        len++;
      }

      callback(ptr, curr, len);
      break;
    }

    case PRINT_FORMAT_ULONG: {
      unsigned long value = va_arg(args, unsigned long);
      char* curr = buffer + sizeof(buffer);

      do {
        *--curr = value % 10 + '0';
        value /= 10;
        len++;
      } while (value != 0);

      callback(ptr, curr, len);
      break;
    }

    case PRINT_FORMAT_ULONGLONG: {
      unsigned long long value = va_arg(args, unsigned long long);
      char* curr = buffer + sizeof(buffer);

      do {
        *--curr = value % 10 + '0';
        value /= 10;
        len++;
      } while (value != 0);

      callback(ptr, curr, len);
      break;
    }

    case PRINT_FORMAT_STR: {
      const char* value = va_arg(args, const char*);
      if (value != NULL) {
        len = (unsigned)WAF::charactersLength(value); // TODO: UINT_MAX
      }
      else {
        value = "(null)";
        len = 6;
      }
      callback(ptr, value, len);
      break;
    }

    default:
      break;
    }

    start = position + fmt_size;
    position = start;
    count += len;
  }

  return (int)count;
}

}  // namespace wasmux
