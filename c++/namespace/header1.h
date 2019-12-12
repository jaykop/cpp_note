#include <iostream>

namespace header1 {
	
	int foo() {
		std::cout << "header1::foo" << std::endl;
		return 0;
	}
	
	void bar() {
		std::cout << "header1::bar" << std::endl;
	}
}