/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

namespace wasmux {

template <typename T>
struct RemoveReference {
  using Type = T;
};

template <typename T>
struct RemoveReference<T&> {
  using Type = T;
};

template <typename T>
struct RemoveReference<T&&> {
  using Type = T;
};

template <typename T>
struct IsLvalueReference {
  static constexpr bool value = false;
};

template <typename T>
struct IsLvalueReference<T&> {
  static constexpr bool value = true;
};

template <typename T>
constexpr T&& forward(typename RemoveReference<T>::Type& arg)
{
  return static_cast<T&&>(arg);
}

template <typename T>
constexpr T&& forward(typename RemoveReference<T>::Type&& arg)
{
    static_assert(!IsLvalueReference<T>::value, "Cannot forward an rvalue as an lvalue");
    return static_cast<T&&>(arg);
}

} // namespace wasmux

using wasmux::RemoveReference;
using wasmux::IsLvalueReference;
using wasmux::forward;
