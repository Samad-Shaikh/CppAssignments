#ifndef CPPREDIS_VALUESTRING_H
#define CPPREDIS_VALUESTRING_H


#include "ValueBase.h"
#include <string>

class ValueString: public ValueBase {
private:
  std::string m_value;

public:
  ValueString(const std::string &key, const std::string &value);

  ~ValueString() noexcept override;

  void update(const std::string &value);

  void printOn(std::ostream &out) const override;
};


#endif //CPPREDIS_VALUESTRING_H
