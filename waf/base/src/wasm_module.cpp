/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/wasm_module.h>
#include <wasmux/wasm_header.h>
#include <wasmux/cxx/Leb128.h>

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
  return WAF::Leb128Reader<uint32_t,1>::read(bytes);
}

uint32_t get_u32_leb128_2(const uint8_t* bytes)
{
  return WAF::Leb128Reader<uint32_t,2>::read(bytes);
}

uint32_t get_u32_leb128_3(const uint8_t* bytes)
{
  return WAF::Leb128Reader<uint32_t,3>::read(bytes);
}

uint32_t get_u32_leb128_4(const uint8_t* bytes)
{
  return WAF::Leb128Reader<uint32_t,4>::read(bytes);
}

uint32_t get_u32_leb128_5(const uint8_t* bytes)
{
  return WAF::Leb128Reader<uint32_t,5>::read(bytes);
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
