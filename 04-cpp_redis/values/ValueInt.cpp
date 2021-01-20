#include <iostream>
#include "ValueInt.h"

ValueInt::ValueInt(const std::string &key,
                   int value) : ValueBase{key}, m_value{value} {}

ValueInt::~ValueInt() noexcept {
  std::cout << "destructor int" << getKey() << std::endl;
}
void ValueInt::update(int value){
  m_value = value;
}

void ValueInt::printOn(std::ostream &out) const{
  out << getKey() << " = " << m_value << " (int)";
}