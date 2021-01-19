#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include "functions.h"

int main() {
/*  int search_values[] = {1, 2, 3, 4, 5};
  if (searchArray(search_values, sizeof(search_values) / sizeof(int), 3) != 2) {
    std::cout << "searchArray returned an incorrect value!!";
    return 0;
  }
  if (searchArray(search_values, sizeof(search_values) / sizeof(int), 4) != 3) {
    std::cout << "searchArray returned an incorrect value!!";
    return 0;
  }
  std::cout << "searchArray OK!!" << std::endl;
  int values[100];
  int values_count = 0;
  values_count = insertArray(values, values_count, 10);
  values_count = insertArray(values, values_count, 1);
  values_count = insertArray(values, values_count, 8);
  values_count = insertArray(values, values_count, 3);
  values_count = insertArray(values, values_count, 6);
  values_count = insertArray(values, values_count, 5);
  values_count = insertArray(values, values_count, 4);
  values_count = insertArray(values, values_count, 7);
  values_count = insertArray(values, values_count, 2);
  printArray(values, values_count);
  return 0;*/

  std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
// Create a reusable random number generator
  std::uniform_int_distribution<> generator(1, 1000000);

  std::chrono::time_point<std::chrono::system_clock> p1;
  p1 = std::chrono::system_clock::now();

  int* values = {};
  int value_count = 0;

  for(int i = 0; i < 25000; ++i) {
    int value = generator(mersenne);
// insert the value into the array
    values = insertArray(values, &value_count, value);

  }
  std::chrono::time_point<std::chrono::system_clock> p2;
  p2 = std::chrono::system_clock::now();
  std::cout << "Duration: " <<
            std::chrono::duration_cast<std::chrono::milliseconds>(p2 - p1).count()
            << " milliseconds "<< std::endl;

  printArray(values, value_count);
  return EXIT_SUCCESS;
}
