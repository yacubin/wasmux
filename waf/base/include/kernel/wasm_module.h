/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_WASM_MODULE_H
#define _WA_KERNEL_WASM_MODULE_H

#include <kernel/types.h>
#include <kernel/limits.h>

#ifdef __cplusplus
extern "C" {
#endif

const char* wa_strsecid(uint8_t id);

uint32_t get_u32_leb128_1(const uint8_t* bytes);
uint32_t get_u32_leb128_2(const uint8_t* bytes);
uint32_t get_u32_leb128_3(const uint8_t* bytes);
uint32_t get_u32_leb128_4(const uint8_t* bytes);
uint32_t get_u32_leb128_5(const uint8_t* bytes);

struct wa_module_reader {
  int (*read) (struct wa_module_reader*, void* buf, size_t len);
};

static inline int wa_module_reader_read(struct wa_module_reader* reader, void* buf, size_t len)
{
  if (len > INT_MAX)
    return -1;
  return reader->read(reader, buf, len);
}

int wa_module_reader_read_u32(struct wa_module_reader* reader, uint32_t* val);
int wa_module_reader_read_name(struct wa_module_reader* reader, char* buf, size_t len);

#ifdef __cplusplus
}
#endif

#endif /* _WA_KERNEL_WASM_MODULE_H */
