/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

namespace WAF {

template<typename T>
const T& min(const T& a, const T& b) {
  return b < a ? b : a;
}

template<typename T>
const T& max(const T& a, const T& b) {
  return b > a ? b : a;
}

}  // namespace WAF
