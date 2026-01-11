/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SECTION_H
#define _WASMUX_SECTION_H

#define WASMUX_VERSION_SECTION      ".wasmux.version"
#define WASMUX_DESCRIPTION_SECTION  ".wasmux.description"
#define WASMUX_URL_SECTION          ".wasmux.url"

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
