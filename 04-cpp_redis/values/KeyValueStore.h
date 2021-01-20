#ifndef CPPREDIS_KEYVALUESTORE_H
#define CPPREDIS_KEYVALUESTORE_H

#include <vector>
#include "ValueBase.h"

class KeyValueStore {
private:
  std::vector<ValueBase *> m_baseValues;

  int findIndex(const std::string &key) const;

public:
  ~KeyValueStore();

  void store(ValueBase *value);

  const ValueBase &get(const std::string &key) const;

  ValueBase &get(const std::string &key);

  void deleteValue(const std::string &key);

  void printOn(std::ostream &out);
};

#endif //CPPREDIS_KEYVALUESTORE_H
