#include <exception>
#include <iostream>

class Parent : public std::exception {
 public:
  virtual const char* what() const noexcept override { return "Parent!\n"; }
};

class Child : public Parent {
 public:
  const char* what() const noexcept override { return "Child!\n"; }
};

int func(int c) {
  if (c == 1) {
    throw Parent();
  } else if (c == 2) {
    throw Child();
  }
  return 0;
}

int main() {
  int c;
  std::cin >> c;

// bad code
// catch always takes the possible parameter,
// and Parent& p = Child(); is possible
// so in this case, both Parent and Child pass to the first catch!
//   try {
//     func(c);
//   } catch (Parent& p) {
//     std::cout << "Parent Catch!" << std::endl;
//     std::cout << p.what();
//   } catch (Child& c) {
//     std::cout << "Child Catch!" << std::endl;
//     std::cout << c.what();
//   }

// good code
// so here we should swtich the code
  try {
    func(c);
  } catch (Child& c) {
    std::cout << "Child Catch!" << std::endl;
    std::cout << c.what();
  } catch (Parent& p) {
    std::cout << "Parent Catch!" << std::endl;
    std::cout << p.what();
  } 
}