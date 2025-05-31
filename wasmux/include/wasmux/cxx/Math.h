/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

namespace wasmux {

template<typename T>
T min(T a, T b)
{
  return b < a ? b : a;
}

template<typename T>
T max(T a, T b)
{
  return b > a ? b : a;
}

template<typename T>
T abs(T i)
{
  return i < 0 ? -i : i;
}

} // namespace wasmux
