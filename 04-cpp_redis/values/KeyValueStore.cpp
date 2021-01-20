#include <string>
#include <iostream>
#include "KeyValueStore.h"

void fatalError(const std::string &cause){
  throw cause;
}

KeyValueStore::~KeyValueStore() {
  for(ValueBase *value : m_baseValues) {
    delete value;
  }
}

int KeyValueStore::findIndex(const std::string &key) const {
  for(int i = 0; i < m_baseValues.size(); ++i) {
    if(m_baseValues[i]->getKey() == key) {
      return i;
    }
  }
  return -1;
}

void KeyValueStore::store(ValueBase *value) {
  int index = findIndex(value->getKey());
  if(index < 0) {
    m_baseValues.push_back(value);
  } else {
    fatalError(" Value already existed");
  }
}

const ValueBase &KeyValueStore::get(const std::string &key) const {
  int index = findIndex(key);
  if(index >= 0) {
    return *m_baseValues[index];
  } else {
    fatalError(" key: " + key + " not found");
  }
}

ValueBase &KeyValueStore::get(const std::string &key) {
  int index = findIndex(key);
  if(index >= 0) {
    return *m_baseValues[index];
  } else {
    fatalError(" key: " + key + " not found");
  }
}

void KeyValueStore::deleteValue(const std::string &key) {
  int index = -1;
  for(int i = 0; i < m_baseValues.size(); ++i) {
    if(m_baseValues.at(i)->getKey() == key) {
      index = i;
      break;
    }
  }
  if(index >= 0) {
    delete m_baseValues[index];
    m_baseValues.erase(m_baseValues.begin() + index);
  } else {
    fatalError(" key: " + key + " not found");
  }
}

void KeyValueStore::printOn(std::ostream &out) {
  for(ValueBase *valueBase : m_baseValues) {
    valueBase->printOn(out);
    out << std::endl;
  }
}
