#include <iostream>
#include "ValueBase.h"

ValueBase::ValueBase(const std::string &key) : m_key{key} {}

ValueBase::~ValueBase() noexcept {
  std::cout << "destructor base" << std::endl;
}

const std::string &ValueBase::getKey() const {
  return m_key;
}