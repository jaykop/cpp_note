#include <iostream>

// *Since C++ 11, every destructor is noexcept at default.

int foo() noexcept {}

// if this does not run, compilable anyway
int bar(int x) noexcept { throw 1; }

int main() { 
    foo();

    // this causes an runtime error!
    // try{
    //     bar(0);
    // } catch (std::exception& e) {
    //     std::cout << "exception thrown: " << e.what() << "\n";
    // }

}