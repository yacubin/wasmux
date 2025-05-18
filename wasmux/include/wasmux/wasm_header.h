/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_WASM_HEADER_H
#define _WA_KERNEL_WASM_HEADER_H

#include <wasmux/int-types.h>

#define	WASM_MAG0 0x00
#define	WASM_MAG1 'a'
#define	WASM_MAG2 's'
#define	WASM_MAG3 'm'
#define	WASM_MAG_STR "\0asm"
#define WASM_MAG_LEN 4

#define WASM_MAGIC 0x6d736100
#define WASM_VERSION 1

enum {
  WASM_SECTION_CUSTOM_ID = 0,
  WASM_SECTION_TYPE_ID = 1,
  WASM_SECTION_IMPORT_ID = 2,
  WASM_SECTION_FUNCTION_ID = 3,
  WASM_SECTION_TABLE_ID = 4,
  WASM_SECTION_MEMORY_ID = 5,
  WASM_SECTION_GLOBAL_ID = 6,
  WASM_SECTION_EXPORT_ID = 7,
  WASM_SECTION_START_ID = 8,
  WASM_SECTION_ELEMENT_ID = 9,
  WASM_SECTION_CODE_ID = 10,
  WASM_SECTION_DATA_ID = 11,
  WASM_SECTION_DATA_COUNT_ID = 12,
};

enum {
  WASM_IMPORT_FUNC_ID = 0,
  WASM_IMPORT_TABLE_ID = 1,
  WASM_IMPORT_MEM_ID = 2,
  WASM_IMPORT_GLOBAL_ID = 3,
};

struct wasm_header {
  uint32_t magic;
  uint32_t version;
};

#define WASM_MEMTYPE_MAXVAL (1 << 0)
#define WASM_MEMTYPE_SHARED (1 << 1)

struct wasm_memory_info {
  uint32_t min_value;
  uint32_t max_value;
  bool has_max_value;
  bool is_shared;
};

#endif /* _WA_KERNEL_WASM_HEADER_H */
