/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <wasmux/types.h>

static_assert (sizeof(int8_t) == 1, "Type int8_t is not equal to 1");
static_assert (sizeof(uint8_t) == 1, "Type uint8_t is not equal to 1");
static_assert (sizeof(int16_t) == 2, "Type int16_t is not equal to 2");
static_assert (sizeof(uint16_t) == 2, "Type uint16_t is not equal to 2");
static_assert (sizeof(int32_t) == 4, "Type int32_t is not equal to 4");
static_assert (sizeof(uint32_t) == 4, "Type uint32_t is not equal to 4");
static_assert (sizeof(int64_t) == 8, "Type int64_t is not equal to 8");
static_assert (sizeof(uint64_t) == 8, "Type uint64_t is not equal to 8");
static_assert (sizeof(void*) == sizeof(size_t), "Type void* does not match size_t");
static_assert (sizeof(void*) == sizeof(ssize_t), "Type void* does not match ssize_t");
