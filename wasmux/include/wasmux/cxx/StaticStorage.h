/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/cxx/New.h>
#include <wasmux/cxx/TypeTraits.h>

namespace WAF {

template<typename T>
union StaticStorage {
  StaticStorage() {}
  ~StaticStorage() {}

  template<typename... Args>
  void initialize(Args&&... args)
  {
    new (WAF::CtorOnly, &m_value) T(forward<Args>(args)...);
  }

  void finalize()
  {
    m_value.~T();
  }

  const T& operator*() const { return m_value; }
  T& operator*() { return m_value; }

  T* operator->() { return &m_value; }
  const T* operator->() const { return &m_value; }
  
  T* get() const { return &m_value; }

private:
  T m_value;
  unsigned char m_buffer[sizeof(T)];
};

} // namespace WAF

using WAF::StaticStorage;
