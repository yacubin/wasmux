/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wasm_module.h>
#include <wasmux/wasm_header.h>

namespace wasmux {

template<typename T, size_t SIZE> struct Leb128Reader;

template<typename T> struct Leb128Reader<T,1> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0]);
  }
};

template<typename T> struct Leb128Reader<T,2> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] << 7);
  }
};

template<typename T> struct Leb128Reader<T,3> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2]) << 14;
  }
};

template<typename T> struct Leb128Reader<T,4> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2] & 0x7f) << 14
        |  static_cast<T>(data[3]) << 21;
  }
};

template<typename T> struct Leb128Reader<T,5> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2] & 0x7f) << 14
        |  static_cast<T>(data[3] & 0x7f) << 21
        |  static_cast<T>(data[4]) << 28;
  }
};

template<typename T> struct Leb128Reader<T,6> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2] & 0x7f) << 14
        |  static_cast<T>(data[3] & 0x7f) << 21
        |  static_cast<T>(data[4] & 0x7f) << 28
        |  static_cast<T>(data[5]) << 35;
  }
};

template<typename T> struct Leb128Reader<T,7> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2] & 0x7f) << 14
        |  static_cast<T>(data[3] & 0x7f) << 21
        |  static_cast<T>(data[4] & 0x7f) << 28
        |  static_cast<T>(data[5] & 0x7f) << 35
        |  static_cast<T>(data[6]) << 42;
  }
};

template<typename T> struct Leb128Reader<T,8> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2] & 0x7f) << 14
        |  static_cast<T>(data[3] & 0x7f) << 21
        |  static_cast<T>(data[4] & 0x7f) << 28
        |  static_cast<T>(data[5] & 0x7f) << 35
        |  static_cast<T>(data[6] & 0x7f) << 42
        |  static_cast<T>(data[7]) << 49;
  }
};

template<typename T> struct Leb128Reader<T,9> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2] & 0x7f) << 14
        |  static_cast<T>(data[3] & 0x7f) << 21
        |  static_cast<T>(data[4] & 0x7f) << 28
        |  static_cast<T>(data[5] & 0x7f) << 35
        |  static_cast<T>(data[6] & 0x7f) << 42
        |  static_cast<T>(data[7] & 0x7f) << 49
        |  static_cast<T>(data[8]) << 56;
  }
};

template<typename T> struct Leb128Reader<T,10> {
  static inline T read(const uint8_t* data)
  {
    return static_cast<T>(data[0] & 0x7f)
        |  static_cast<T>(data[1] & 0x7f) << 7
        |  static_cast<T>(data[2] & 0x7f) << 14
        |  static_cast<T>(data[3] & 0x7f) << 21
        |  static_cast<T>(data[4] & 0x7f) << 28
        |  static_cast<T>(data[5] & 0x7f) << 35
        |  static_cast<T>(data[6] & 0x7f) << 42
        |  static_cast<T>(data[7] & 0x7f) << 49
        |  static_cast<T>(data[8] & 0x7f) << 56
        |  static_cast<T>(data[9]) << 63;
  }
};

template<typename T, size_t SIZE> struct Leb128Writer;

template<typename T> struct Leb128Writer<T,1> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value);
  }
};

template<typename T> struct Leb128Writer<T,2> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>(value >> 7);
  }
};

template<typename T> struct Leb128Writer<T,3> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>(value >> 14);
  }
};

template<typename T> struct Leb128Writer<T,4> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>((value >> 14) | 0x80);
    out[3] = static_cast<uint8_t>(value >> 21);
  }
};

template<typename T> struct Leb128Writer<T,5> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>((value >> 14) | 0x80);
    out[3] = static_cast<uint8_t>((value >> 21) | 0x80);
    out[4] = static_cast<uint8_t>(value >> 28);
  }
};

template<typename T> struct Leb128Writer<T,6> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>((value >> 14) | 0x80);
    out[3] = static_cast<uint8_t>((value >> 21) | 0x80);
    out[4] = static_cast<uint8_t>((value >> 28) | 0x80);
    out[5] = static_cast<uint8_t>(value >> 35);
  }
};

template<typename T> struct Leb128Writer<T,7> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>((value >> 14) | 0x80);
    out[3] = static_cast<uint8_t>((value >> 21) | 0x80);
    out[4] = static_cast<uint8_t>((value >> 28) | 0x80);
    out[5] = static_cast<uint8_t>((value >> 35) | 0x80);
    out[6] = static_cast<uint8_t>(value >> 42);
  }
};

template<typename T> struct Leb128Writer<T,8> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>((value >> 14) | 0x80);
    out[3] = static_cast<uint8_t>((value >> 21) | 0x80);
    out[4] = static_cast<uint8_t>((value >> 28) | 0x80);
    out[5] = static_cast<uint8_t>((value >> 35) | 0x80);
    out[6] = static_cast<uint8_t>((value >> 42) | 0x80);
    out[7] = static_cast<uint8_t>(value >> 49);
  }
};

template<typename T> struct Leb128Writer<T,9> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>((value >> 14) | 0x80);
    out[3] = static_cast<uint8_t>((value >> 21) | 0x80);
    out[4] = static_cast<uint8_t>((value >> 28) | 0x80);
    out[5] = static_cast<uint8_t>((value >> 35) | 0x80);
    out[6] = static_cast<uint8_t>((value >> 42) | 0x80);
    out[7] = static_cast<uint8_t>((value >> 49) | 0x80);
    out[8] = static_cast<uint8_t>(value >> 56);
  }
};

template<typename T> struct Leb128Writer<T,10> {
  static inline void write(T value, uint8_t* out)
  {
    out[0] = static_cast<uint8_t>(value | 0x80);
    out[1] = static_cast<uint8_t>((value >> 7) | 0x80);
    out[2] = static_cast<uint8_t>((value >> 14) | 0x80);
    out[3] = static_cast<uint8_t>((value >> 21) | 0x80);
    out[4] = static_cast<uint8_t>((value >> 28) | 0x80);
    out[5] = static_cast<uint8_t>((value >> 35) | 0x80);
    out[6] = static_cast<uint8_t>((value >> 42) | 0x80);
    out[7] = static_cast<uint8_t>((value >> 49) | 0x80);
    out[8] = static_cast<uint8_t>((value >> 56) | 0x80);
    out[9] = static_cast<uint8_t>(value >> 63);
  }
};

template<typename T> struct Leb128Traits;

template<> struct Leb128Traits<uint8_t> {
  typedef uint8_t Buffer[2];
  static constexpr size_t size = 2;
  static inline bool checkTerminal(uint8_t b)
  {
    return (b & 0xfe) == 0;
  }
};

template<> struct Leb128Traits<uint16_t> {
  typedef uint8_t Buffer[3];
  static constexpr size_t size = 3;
  static inline bool checkTerminal(uint8_t b)
  {
    return (b & 0xfc) == 0;
  }
};

template<> struct Leb128Traits<uint32_t> {
  typedef uint8_t Buffer[5];
  static constexpr size_t size = 5;
  static inline bool checkTerminal(uint8_t b)
  {
    return (b & 0xf0) == 0;
  }
};

template<> struct Leb128Traits<uint64_t> {
  typedef uint8_t Buffer[10];
  static constexpr size_t size = 10;
  static inline bool checkTerminal(uint8_t b)
  {
    return (b & 0xfe) == 0;
  }
};

template<typename T, size_t COUNT> struct Leb128Parser;
template<typename T> struct Leb128Parser<T,0> {};
template<typename T> struct Leb128Parser<T,1> {
  static inline size_t parse(const uint8_t* start, const uint8_t* end, T& value)
  {
    constexpr size_t size = Leb128Traits<T>::size;
    constexpr size_t lastIndex = size - 1;
    if (start + lastIndex < end && (start[lastIndex] & 0x80) == 0) {
      if (!Leb128Traits<T>::checkTerminal(start[lastIndex])) {
        value = Leb128Reader<T, size>::read(start);
        return size;
      }
    }
    return 0;
  }
};

template<typename T, size_t COUNT> struct Leb128Parser {
  static inline size_t parse(const uint8_t* start, const uint8_t* end, T& value)
  {
    constexpr size_t index = Leb128Traits<T>::size - COUNT;
    constexpr size_t size = index + 1;
    if (start + index < end && (start[index] & 0x80) == 0) {
      value = Leb128Reader<T, size>::read(start);
      return size;
    }
    return Leb128Parser<T, COUNT - 1>::parse(start, end, value);
  }
};

template<typename T>
size_t readLeb128(const void* data, size_t size, T& value)
{
  return Leb128Parser<T,Leb128Traits<T>::size>::parse(static_cast<const uint8_t*>(data), static_cast<const uint8_t*>(data) + size, value);
}

template<typename T>
size_t writeLeb128(T value, void* data)
{
  size_t size = 0;

  for (;;) {
    uint8_t byte = value & 0x7f;
    value >>= 7;
    if (value == 0) {
      reinterpret_cast<uint8_t*>(data)[size++] = byte;
      break;
    }
    reinterpret_cast<uint8_t*>(data)[size++] = byte | 0x80;
  }

  return size;
}

} // namespace wasmux

const char* wa_strsecid(uint8_t id)
{
  switch (id) {
  case WASM_SECTION_CUSTOM_ID:
    return "Custom";
  case WASM_SECTION_TYPE_ID:
    return "Type";
  case WASM_SECTION_IMPORT_ID:
    return "Import";
  case WASM_SECTION_FUNCTION_ID:
    return "Function";
  case WASM_SECTION_TABLE_ID:
    return "Table";
  case WASM_SECTION_MEMORY_ID:
    return "Memory";
  case WASM_SECTION_GLOBAL_ID:
    return "Global";
  case WASM_SECTION_EXPORT_ID:
    return "Export";
  case WASM_SECTION_START_ID:
    return "Start";
  case WASM_SECTION_ELEMENT_ID:
    return "Element";
  case WASM_SECTION_CODE_ID:
    return "Code";
  case WASM_SECTION_DATA_ID:
    return "Data";
  case WASM_SECTION_DATA_COUNT_ID:
    return "DataCount";
  }

  return "";
}

uint32_t get_u32_leb128_1(const uint8_t* bytes)
{
  return wasmux::Leb128Reader<uint32_t,1>::read(bytes);
}

uint32_t get_u32_leb128_2(const uint8_t* bytes)
{
  return wasmux::Leb128Reader<uint32_t,2>::read(bytes);
}

uint32_t get_u32_leb128_3(const uint8_t* bytes)
{
  return wasmux::Leb128Reader<uint32_t,3>::read(bytes);
}

uint32_t get_u32_leb128_4(const uint8_t* bytes)
{
  return wasmux::Leb128Reader<uint32_t,4>::read(bytes);
}

uint32_t get_u32_leb128_5(const uint8_t* bytes)
{
  return wasmux::Leb128Reader<uint32_t,5>::read(bytes);
}

int wa_module_reader_read_u32(struct wa_module_reader* reader, uint32_t* val)
{
  ssize_t rv;
  uint8_t buf[5];

  rv = wa_module_reader_read(reader, &buf[0], 1);
  if (rv != 1) {
    return (rv < 0) ? rv : -1;
  }
  if ((buf[0] & 0x80) == 0) {
    *val = get_u32_leb128_1(buf);
    return 1;
  }

  rv = wa_module_reader_read(reader, &buf[1], 1);
  if (rv != 1) {
    return (rv < 0) ? rv : -1;
  }
  if ((buf[1] & 0x80) == 0) {
    *val = get_u32_leb128_2(buf);
    return 2;
  }

  rv = wa_module_reader_read(reader, &buf[2], 1);
  if (rv != 1) {
    return (rv < 0) ? rv : -1;
  }
  if ((buf[2] & 0x80) == 0) {
    *val = get_u32_leb128_3(buf);
    return 3;
  }

  rv = wa_module_reader_read(reader, &buf[3], 1);
  if (rv != 1) {
    return (rv < 0) ? rv : -1;
  }
  if ((buf[3] & 0x80) == 0) {
    *val = get_u32_leb128_4(buf);
    return 4;
  }

  rv = wa_module_reader_read(reader, &buf[4], 1);
  if (rv != 1) {
    return (rv < 0) ? rv : -1;
  }
  if ((buf[4] & 0xf0) == 0) {
    *val = get_u32_leb128_5(buf);
    return 5;
  }

  return -1;
}

int wa_module_reader_read_name(struct wa_module_reader* reader, char* buf, size_t len)
{
  int retval;
  uint32_t length;

  retval = wa_module_reader_read_u32(reader, &length);
  if (retval < 0)
    return retval;

  if (length >= INT_MAX || len < (length + 1))
    return -1;

  int sz = retval;
  retval = wa_module_reader_read(reader, buf, length);
  if (retval < 0)
    return retval;

  buf[length] = '\0';
  return sz + retval;
}
