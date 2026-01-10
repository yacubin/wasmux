/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/section.h>

#define MANIFEST_JSON                                            \
  "{"                                                            \
    "\\\"initPages\\\":" __STRINGIFY(WASMUX_CORE_INIT_PAGES) "," \
    "\\\"maxPages\\\":"  __STRINGIFY(WASMUX_CORE_MAX_PAGES)      \
  "}"

WA_CUSTOM_SECTION_STR(WASMUX_VERSION_SECTION, WASMUX_VERSION);
WA_CUSTOM_SECTION_STR(WASMUX_MANIFEST_SECTION, MANIFEST_JSON);
