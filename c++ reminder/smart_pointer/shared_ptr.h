#pragma once
#include <memory>
#include "classA.h"

using namespace std;

void func1()
{

	// copies the pointer with reference counting
	std::shared_ptr<A> pa(new A);
	std::shared_ptr<A> pb = pa;
}

void func2()
{
	// * how does it count?
	// they are sharing control block
	// they gets the address of control block
	// keeps updating the ref count of it

	// everytime shared_ptr allocated -> increase,
	// deallocated -> decrease

	// when it calls destructor?
	vector<std::shared_ptr<A>>  v;
	v.push_back(std::shared_ptr<A>(new A));
	v.push_back(v[0]);
	v.push_back(v[1]);

	std::cout << v.begin()->use_count() << std::endl;
	v.erase(v.begin());
	std::cout << v.begin()->use_count() << std::endl;
	v.erase(v.begin());
	std::cout << v.begin()->use_count() << std::endl;
	v.erase(v.begin());
	// std::cout << v.begin()->use_count() << std::endl;
}

void func3()
{
	shared_ptr<A> p1 = std::make_shared<A>(); // c++!4

	// this generates multiple control blocks
	// -> occurs an error of double free
	// * DO NOT ALLOCATE SHARED_PTR WITH ADDRESS
	A* a = new A();

	shared_ptr<A> p2(a);
	shared_ptr<A> p3(a);

	// both 2
	std::cout << p2.use_count() << std::endl;
	std::cout << p3.use_count() << std::endl;
}

void func4()
{
	shared_ptr<A> p2 = std::make_shared<A>();
	shared_ptr<A> p3 = p2->get_shared_ptr();

	// both 1 -> individual control block
	std::cout << p2.use_count() << std::endl;
	std::cout << p3.use_count() << std::endl;
}

void func5()
{
	std::shared_ptr<A> p1 = std::make_shared<A>();
	std::shared_ptr<A> p2 = std::make_shared<A>();

	p1->set_other(p2);
	p2->set_other(p1);

	// both 2
	std::cout << p1.use_count() << std::endl;
	std::cout << p2.use_count() << std::endl;

	// => use weak_ptr
	// 1. weak_ptr takes only pointer with control block
	// 2. does not increase the ref count
	// 3. using lock(), we can check if the weak_ptr is deleted already or not
}

void shared_ptr_main()
{
	// func1();
	// func2();
	// func3();
	// func4();
	func5();
}