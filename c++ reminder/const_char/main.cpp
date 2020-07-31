#include <string>
#include <iostream>

class A
{
public:
	const char * s = "asdfasdf";
};

int main()
{
	std::string_view s;
	A* a = new A;
	s = a->s;
	delete a;

	std::string s1;
	std::string_view s2;

	std::cout << sizeof(s1) << " " << sizeof(s2);

	return 0;
}