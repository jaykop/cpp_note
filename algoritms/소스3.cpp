#include <iostream>
#include <vector>

using namespace std;

class Base
{
public :
	Base()
	{
		cout << "Base constructor\n";
	}

	~Base()
	{
		cout << "Base destructor\n";
	}
};

class Derived : public Base
{
public:
	Derived() 
	{
		cout << "Derived constructor\n";
	}

	virtual ~Derived()
	{
		cout << "Derived destructor\n";
	}
};

void bubble(vector<int>& v)
{
	int size = static_cast<int>(v.size());
	for (int i = 0; i < size - 1; ++i)
	{
		bool swapped = false;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

void insertion(vector<int>& v)
{
	int size = static_cast<int>(v.size());
	for (int i = 1; i < size; ++i)
	{
		for (int j = i; j > 0; --j)
			if (v[j] < v[j - 1])
				swap(v[j], v[j - 1]);
	}
}

int main()
{
	//Base* b1 = new Base;
	//Base* b2 = new Derived;
	//delete b1;
	//delete b2;

	// Base constructor
	// Base constructor
	// Derived constructor
	// Base destructor
	// Derived destructor
	// Base destructor

	vector<int> v = { 7, 4, 1, 3, 8, 6, 9, 5, 2 };
	insertion(v);
	// bubble(v);

	return 0;
}