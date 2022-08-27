#include <iostream>

constexpr int Fibonacci(int n){
  switch (n) {
    case 0: return 0;
    case 1:return 1;
    default:
      return Fibonacci(n-1) + Fibonacci(n-2);
  }
}

int main() {
  std::cout << "Constant Expression evaluated and executed at Compile time" << std::endl;

  // static assert -> check the value at compile time
//  static_assert(Fibonacci(10) == 55, "Incorrect Fibonacci number");

  // Compile time error here
//  static_assert(Fibonacci(10) == 1, "Incorrect Fibonacci number");

  return 0;
}
