
/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Section.h>

WA_CUSTOM_SECTION_STR(".wasmux.version", WASMUX_VERSION);
WA_CUSTOM_SECTION_STR(".wasmux.description", WASMUX_DESCRIPTION);
WA_CUSTOM_SECTION_STR(".wasmux.url", WASMUX_URL);

__attribute__((export_name("_xxx")))
void _xxx(void)
{
}
