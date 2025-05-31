/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SECTION_H
#define _WASMUX_SECTION_H

#ifdef __wasm__
# define WA_CUSTOM_SECTION_STR(name, message) \
  __asm( \
    ".section .custom_section." name ",\"\",@\n" \
    ".ascii \"" message "\"\n" \
  )
#else
# define WA_CUSTOM_SECTION_STR(name, message) \
  __asm( \
    ".section " name ",\"\"\n" \
    ".ascii \"" message "\"\n" \
  )
#endif

#endif /* _WASMUX_SECTION_H */
