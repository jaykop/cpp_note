#include "casting.h"

/* 
* casting order when using c-style casting

* 1. const_cast
* 2. static_cast
* 3. static_cast with const
* 4. reinterpret_cast
* 5. reinterpret_cast with const

* https://en.cppreference.com/w/cpp/language/explicit_cast
*/ 

int main()
{
	std::cout << "* implicit casting *\n";
	int i1 = 97;
	char c = i1;
	std::cout << "int val: " << i1 << " / char val:" << c << "\n";
	std::cout << "\n";
	std::cout << "* explicit casting *\n";
	int i2 = 65;
	std::cout << "int val: " << i2 << " / char val:" << char(i2) << "\n";
	std::cout << "\n";
	upcasting_and_downcasting();
	std::cout << "\n";
	dynamic_casting();
	std::cout << "\n";

	/*
	* !!Reason why you should not use c-style casting!!

	* 1. as already mentioned, no checking is performed here. 
	* The programmer simply cannot know which of the various casts is used which weakens strong typing

	* 2. the new casts are intentionally visually striking.
	* Since casts often reveal a weakness in the code, it's argued that making casts visible in the code is a good thing.

	* 3. this is especially true if searching for casts with an automated tool.
	* Finding C - style casts reliably is nearly impossible.

	* https://stackoverflow.com/questions/4775781/what-is-the-difference-between-c-like-casting-and-functional-casting
	* https://stackoverflow.com/questions/32168/c-cast-syntax-styles
	* https://stackoverflow.com/questions/3484371/whats-the-difference-between-typemyvar-and-typemyvar
	* https://stackoverflow.com/questions/1652396/what-is-the-difference-between-typevalue-and-typevalue
	*/

	// no difference
	int x = (int)5.1;
	int y = int(5.1);

	return 0;
}