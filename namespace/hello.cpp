#include <iostream>
#include "namespace.h"

using header1::foo; //foo func is always from header1
using namespace header1; //all the funcs from header1 is usable w/o  header1::

void test()
{
	only_in_this_file = 100;
}

// This cccurs an error
only_in_this_file = 97;

int main () {
	
	std::cout << "Hello, World!!" << std::endl;
	header1::func();
	
	test();
	
	std::cout << only_in_this_file << std::endl;
	std::cout << OnlyInThisFile() << std::endl;
	
	return 0;
}

// Do not declare using namspace std;
// By updating std library, conflicts could occur
// Just std:: evevry time
 