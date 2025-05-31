/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

namespace wasmux {

template<typename T>
class Atomic {
public:
  Atomic() {}
  Atomic(T counter) : m_counter(counter) {}

  inline T load() const
  {
    return __atomic_load_n(&m_counter, __ATOMIC_SEQ_CST);
  }

  void store(T value)
  {
    __atomic_store_n(&m_counter, value, __ATOMIC_SEQ_CST);
  }

  inline T fetchAdd(T value)
  {
    return __atomic_fetch_add(&m_counter, value, __ATOMIC_SEQ_CST);
  }

  T operator++()
  {
    return __atomic_add_fetch(&m_counter, 1, __ATOMIC_SEQ_CST);
  }

  T operator++(T)
  {
    return __atomic_fetch_add(&m_counter, 1, __ATOMIC_SEQ_CST);
  }

  T operator+(const Atomic& value) const
  {
    T counter = load();
    return __atomic_add_fetch(&counter, value, __ATOMIC_SEQ_CST);
  }

private:
  T m_counter;
};

} // namespace wasmux
