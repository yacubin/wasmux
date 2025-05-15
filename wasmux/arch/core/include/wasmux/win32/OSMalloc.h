/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/wei.h>

namespace WEI {

void* OSMalloc(size_t size);
void* OSZeroMalloc(size_t size);
void OSFree(void* ptr);

} // namespace WEI
