#pragma once
#include <memory>
#include <vector>
#include "classA.h"

void thrower()
{
	throw 1;
}

// passing unique ptr as referenc
// using it just as a wrapper
void func1(std::unique_ptr<A>& ptr)
{
	ptr->data[0] = 1;
}

// correct method
void func2(A* ptr)
{
	ptr->data[0] = 1;
}

void do_something()
{
	// A* a = new A;
	std::unique_ptr<A> pa(new A);
	pa->dodo();
	std::cout << pa->data[0] << std::endl;
	// move reference -> pa becomes empty
	std::unique_ptr<A> pb = std::move(pa);
	pb->dodo();
	std::cout << pb->data[0] << std::endl;
	std::cout << pa.get() << std::endl;
	func1(pb);
	std::cout << pb->data[0] << std::endl;
	func1(pb);
	std::cout << pb->data[0] << std::endl;
	// thrower();

	// delete a;
}

void unique_ptr_main()
{
	// A* a = new A;
	// delete a;

	//try
	//{
	do_something();
	//}
	//catch (int i)
	//{
	//	std::cout << "exception\n";
	//}

	// how to use with vector
	std::vector<std::unique_ptr<A>> v;
	v.push_back(std::unique_ptr<A>(new A));
	v.emplace_back(new A); // simple way
	auto pa2 = std::make_unique<A>(); // c++14
	v.push_back(std::move(pa2)); // adding existing pointer into v
}