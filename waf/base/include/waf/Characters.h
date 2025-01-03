/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <kernel/types.h>

namespace {

template<size_t SIZE> struct IntHelper;
template<> struct IntHelper<1> {
  using SType = int8_t;
  using UType = uint8_t;
};
template<> struct IntHelper<2> {
  using SType = int16_t;
  using UType = uint16_t;
};
template<> struct IntHelper<4> {
  using SType = int32_t;
  using UType = uint32_t;
};
template<> struct IntHelper<8> {
  using SType = int64_t;
  using UType = uint64_t;
};

}  // namespace

namespace WAF {

template<typename CHAR>
size_t charactersLength(const CHAR* characters)
{
  const auto* ptr = characters;
  while (*ptr) {
    ptr++;
  }

  return ptr - characters;
}

template<typename CHAR>
size_t charactersLength(const CHAR* characters, size_t length)
{
  size_t n = 0;
  while (n < length && characters[n]) {
    n++;
  }

  return n;
}

template<typename CHAR>
int charactersCompare(const CHAR* characters1, const CHAR* characters2)
{
  using UChar = typename IntHelper<sizeof(CHAR)>::UType;

  UChar c1, c2;

  for (;;) {
    c1 = static_cast<UChar>(*characters1);
    c2 = static_cast<UChar>(*characters2);

    if (c1 != c2)
      return c1 < c2 ? -1 : 1;

    if (!c1)
      break;

    characters1++;
    characters2++;
  }

  return 0;
}

template<typename CHAR>
CHAR* charactersCopy(CHAR* dst, const CHAR* src)
{
  CHAR* ret = dst;
  for (;;) {
    CHAR ch = *dst = *src;
    if (ch == '\0')
      break;
    src++;
    dst++;
  }

  return ret;
}

}  // namespace WAF
