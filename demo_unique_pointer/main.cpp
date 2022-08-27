#include <iostream>
#include <memory>

class X {
public:
  X(){
    std::cout << "X ctor" << std::endl;
  }

  ~X(){
    std::cout << "X ~dtor" << std::endl;
  }

  void sayHi(){
    std::cout << "X says hi! :]" << std::endl;
  }
};

int main() {
  auto pX = std::make_unique<X>();
  pX->sayHi();
  return EXIT_SUCCESS;
}
