#ifndef CPPREDIS_VALUEBASE_H
#define CPPREDIS_VALUEBASE_H

#include <string>
#include <ostream>

class ValueBase {
private:
  std::string m_key;
protected:
  ValueBase(const std::string &key);

public:
  virtual ~ValueBase() noexcept;
  const std::string &getKey() const;
  // const -> no object modification within the the function call
  // = 0 -> pure virtual function, equals to the 'abstract' keyword
  virtual void printOn(std::ostream &out) const = 0;
};

#endif //CPPREDIS_VALUEBASE_H
