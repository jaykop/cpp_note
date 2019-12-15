#include <iostream>

namespace header2 {
	
	int foo() {
		std::cout << "header2::foo" << std::endl;
		return 0;
	}
	
	void bar() {
		std::cout << "header2::bar" << std::endl;
	}
}