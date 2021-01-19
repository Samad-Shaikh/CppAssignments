//
// Created by samad.shaikh on 24/11/2020.
//

#include <iostream>
#include "functions.h"

//void printArray(int values[], int values_count) { is Same as below
void printArray(int* values, int values_count) {
  if(!values) return;
  for (int i = 0; i < values_count; ++i) {
//    std::cout << (i > 0 ? ", " : "") << values[i];
        std::cout << values[i];
        if(i == values_count -1) {
            std::cout << ",";
        }
  }
  std::cout << std::endl;
}
