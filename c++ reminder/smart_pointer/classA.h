#pragma once
#include <iostream>

class A : public std::enable_shared_from_this<A>
{
public:

	int* data = nullptr;
	// std::shared_ptr<A> other;
	std::weak_ptr<A> other;

	A()
	{
		data = new int[10];
		std::cout << "allocated\n";
	}

	void dodo()
	{
		for (int i = 0; i < 10; i++)
			data[i] = i;
	}

	~A()
	{
		delete[] data;
		data = nullptr;
		std::cout << "deallocated\n";
	}

	std::shared_ptr<A> get_shared_ptr() 
	{ 
		return shared_from_this();
		// return std::shared_ptr<A>(this);
	}

	// void set_other(std::shared_ptr<A> a) { other = a; }
	void set_other(std::weak_ptr<A> a) { other = a; }
};