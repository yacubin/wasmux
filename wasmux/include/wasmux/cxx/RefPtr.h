/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

namespace WAF {

template<typename T>
class RefPtr {
public:
  RefPtr() : m_ptr(nullptr) {}
  RefPtr(T* ptr)
    : m_ptr(ptr)
  {
    if (m_ptr)
      m_ptr->ref();
  }

  RefPtr(const RefPtr& other)
    : m_ptr(other.m_ptr)
  {
    if (m_ptr)
      m_ptr->ref();
  }

  template<typename U>
  RefPtr(const RefPtr<U>& other)
    : m_ptr(other.m_ptr)
  {
    if (m_ptr)
      m_ptr->ref();
  }

  template<typename U>
  RefPtr(RefPtr<U>&& other)
    : m_ptr(other.m_ptr)
  {
    other.m_ptr = nullptr;
  }

  ~RefPtr()
  {
    if (m_ptr)
      m_ptr->unref();
  }

  T* get() const
  {
    return m_ptr;
  }

  T* operator->() const
  {
    return m_ptr;
  }

  T& operator*() const
  {
    return *m_ptr;
  }

  template<typename U>
  RefPtr& operator=(U* other)
  {
    if (other)
      other->ref();
    if (m_ptr)
      m_ptr->unref();
    m_ptr = other;
    return *this;
  }

  RefPtr& operator=(const RefPtr& other)
  {
    if (m_ptr)
      m_ptr->unref();
    m_ptr = other.m_ptr;
    if (m_ptr)
      m_ptr->ref();
    return *this;
  }

  template<typename U>
  RefPtr& operator=(const RefPtr<U>& other)
  {
    if (m_ptr)
      m_ptr->unref();
    m_ptr = other.m_ptr;
    if (m_ptr)
      m_ptr->ref();
    return *this;
  }

  template<typename U>
  RefPtr& operator=(RefPtr<U>&& other)
  {
    if (m_ptr)
      m_ptr->unref();
    m_ptr = other.m_ptr;
    if (m_ptr)
      m_ptr->ref();
    return *this;
  }

private:
  enum NewRefConstructorTag { NewRefConstructor };
  RefPtr(NewRefConstructorTag, T* ptr) : m_ptr(ptr) {}

  template<typename U>
  friend RefPtr<U> newRef(U*);

  template<typename U>
  friend class RefPtr;

  T* m_ptr;
};

template<typename T>
RefPtr<T> newRef(T* ptr)
{
  return RefPtr<T>(RefPtr<T>::NewRefConstructor, ptr);
}

} // namespace WAF

using WAF::RefPtr;
using WAF::newRef;
