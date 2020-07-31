#include <iostream>

template <typename T>
struct A
{
	void function()
	{
		std::cout << "asdf";
	}
	T a = 0;
	int b = 0;
	virtual void function2()
	{
		std::cout << "asdf";
	}
};

int main()
{
	A<float>* a = new A<float>;
	a->function2();
	delete a;

	/*int a = 3;
	switch (a)
	{
	case 1:
		a = 1;
		break;
	case 2:
		a = 2;
		break;
	case 3:
		a = 3;
		break;
	default:
		break;
	}

	if (a == -1)
		a = -1;
	else if (a == 0)
		a = 0;
	else if (a == 1)
		a = 1;
	else
		a = 2;*/

	return 0;
}