#include <iostream>

int main()
{
	enum A : char { ONE = 4, TWO = 3, THREE };
	A a = THREE;
	enum class COLOR : int {WHITE, RED, BLUE, BLACK, YELLOW, END};
	enum class PEOPLE : unsigned int {WHITE, BLACK, YELLOW, END};


	std::cout << int(a);
	std::cout << std::endl;

	//COLOR p = WHITE;

	//std::cout << sizeof(p);
	//std::cout << std::endl;

	//for (unsigned int i = 0; i < COLOR::END; ++i)
	//	std::cout << i;


	return 0;
}