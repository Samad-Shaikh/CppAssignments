#include <iostream>
#include <chrono>
#include <sstream>
#include "values/ValueBase.h"
#include "values/ValueInt.h"
#include "values/ValueString.h"
#include "values/KeyValueStore.h"

std::string IntToString(int value){
  std::ostringstream output;
  output << value;
  return output.str();
}


void run() {
  KeyValueStore keyValueStore;
  std::chrono::time_point<std::chrono::system_clock> start;
  start = std::chrono::system_clock::now();

  constexpr size_t number_of_keys = 10;

  // Create kvp with names int_1..number_of_keys and int values 1..number_of_keys
  // Create kvp with names str_1..number_of_keys and string values text 1..number_of_keys
  for(size_t i = 1; i <= number_of_keys; ++i) {
    keyValueStore.store(new ValueInt("int_" + IntToString(i), i));
    keyValueStore.store(new ValueString("str_" + IntToString(i), "text " + IntToString(i)));
  }
  for(size_t i = 1; i <= number_of_keys; ++i) {
    std::string key = "int_" + IntToString(i);
    const ValueBase &valueBase = keyValueStore.get(key);
    std::ostringstream oStringStream;
    valueBase.printOn(oStringStream);
    std::string expected = (key + " = " + IntToString(i) + " (int)");
    if(oStringStream.str() != expected) {
      std::cout << "Wrong valueBase returned for key: " << key
                << ", value was: " << oStringStream.str()
                << ", expected: " << expected << std::endl;
    }
  }

  // delete int kvp
  for(size_t i = 1; i <= number_of_keys; ++i) {
    std::string key = "int_" + IntToString(i);
    keyValueStore.deleteValue(key);
  }

  std::chrono::time_point<std::chrono::system_clock> stop;
  stop = std::chrono::system_clock::now();
  std::cout << "Duration: " <<
            std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()
            << " milliseconds " << std::endl;
  keyValueStore.printOn(std::cout);
//  keyValueStore.deleteValue("Noob power 999");
}

int main() {
  try {
    run();
  } catch(const std::string &cause) {
    std::cerr << "Fatal error" << cause << std::endl;
  }
  return EXIT_SUCCESS;
}
