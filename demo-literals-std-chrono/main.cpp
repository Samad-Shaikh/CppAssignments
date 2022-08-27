#include <iostream>
#include <chrono>
using namespace std::chrono;

void print(milliseconds ms) {
  std::cout << ms.count() << "ms" << std::endl;
}

int main() {
  auto x = 2s;
  std::cout << "x = 2s : ";
  print(x);

  auto y = 150ms;
  std::cout << "y = 150ms: ";
  print(y);

  auto z = x+y;
  std::cout << "z = x + y: ";
  print(z);

  constexpr auto timeLimit = 3s;
  std::cout << "\n Time limit is ";
  print(timeLimit);

  if (z < timeLimit) {
    std::cout << " All ok!" << std::endl;
  }
  return EXIT_SUCCESS;
}
