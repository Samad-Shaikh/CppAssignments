#include <iostream>
#include "ValueString.h"

ValueString::ValueString(const std::string &key, const std::string &value) : ValueBase{key}, m_value{value} {}

ValueString::~ValueString() noexcept{
  std::cout << "destructor string " << getKey() << std::endl;
}

void ValueString::update(const std::string &value) {
  m_value = value;
}

void ValueString::printOn(std::ostream &out) const {
  out << getKey() << "=" << m_value << " (string)";
}
