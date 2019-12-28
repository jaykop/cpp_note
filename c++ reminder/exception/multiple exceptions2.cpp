#include <iostream>
#include <stdexcept>

int func(int c) {
  if (c == 1) {
    throw 1;
  } else if (c == 2) {
    throw "hi";
  } else if (c == 3) {
    throw std::runtime_error("error");
  }
  return 0;
}

int main() {
  int c;
  std::cin >> c;

  try {
    func(c);
  } catch (int e) {
    std::cout << "Catch int : " << e << std::endl;
  }
// When defined inside a template class,
// the type of exception can be changed by the instantiation method.
// So need to consider the type of exception insdie the instant
  catch (...) {
    std::cout << "Default Catch!" << std::endl;
  }
}