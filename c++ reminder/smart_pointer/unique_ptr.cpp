#include <iostream>

class A {
  int *data;

 public:
  A() {
    data = new int[100];
    std::cout << "Gained memory!" << std::endl;
  }

  ~A() {
    std::cout << "Called destructor" << std::endl;
    delete[] data;
  }
};

void do_something() { 
    
    A *pa = new A(); 
    // delete pa;
}

int main() {
  do_something();

  // Never released the gained memory
  // cuz did not call the destructor
  // 4 * 100 bytes leaked
}