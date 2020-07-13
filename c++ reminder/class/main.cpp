#include <iostream>

class Empty
{
	// char c;
};

class A
{
	// 
	static int sa;

	//char c1; // 1
	//int a; // 4
	//float b; // 4
	//char c2; // 1
	//double d; // 8

	void func() {}
	void func2() {}
	void func3() {}

	// added pointer +4
	virtual void func4() {}
};

int main()
{
	unsigned size = sizeof(Empty);
	//char c;
	//int a;
	//double d;
	//size_t size1 = sizeof(d);
	size_t size2 = sizeof(A);
	std::cout << size2 << "\n";

	return 0;
}