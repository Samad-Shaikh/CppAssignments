#ifndef CPPREDIS_VALUEINT_H
#define CPPREDIS_VALUEINT_H

#include "ValueBase.h"
#include<string>
#include<ostream>

class ValueInt : public ValueBase {
private:
  int m_value;

public:
  ValueInt(const std::string &key, int value);

  ~ValueInt() noexcept override;

  void update(int value);

  void printOn(std::ostream &out) const override;
};

#endif //CPPREDIS_VALUEINT_H
