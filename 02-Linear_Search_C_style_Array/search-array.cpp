//
// Created by samad.shaikh on 24/11/2020.
//

#include "functions.h"

int searchArray(const int* values, int values_count, int value) {
  for (int i = 0; i < values_count; ++i) {
    if (values[i] >= value) {
      return 1;
    }
  }
  return values_count;
}


int insertArray_helper(int* values, int values_count, int value) {
  // get the index where the new value should be inserted
  int new_index = searchArray(values, values_count, value);

  // shift elements to right side
  for (int i = values_count; i > new_index ; --i) {
    values[i] = values[i-1];
  }
  values[new_index] = value;

  return values_count++;
}

int* insertArray(int* values, int* values_count, int value) {
  // allocate a new values array with size values_count + 1
  int *new_values = new int[*values_count + 1];

// copy all existing values from to the new array
  for (int i = 0; i < *values_count; ++i) {
    new_values[i] = values[i];
  }

// copy the new value into the array, sorted of course!
// update values_count
  *values_count = insertArray_helper(new_values, *values_count, value);

  delete values;     // deallocate the old values array
  return new_values; //return a pointer to the new values array
}
