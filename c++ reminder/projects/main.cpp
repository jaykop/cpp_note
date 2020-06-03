/* RAII: Resource Acquisition Is Initialization
* Allocated memory to be returned once it gets out of the scope
* smart pointer -> pointer in stack (not heap)/(stack unwinding)
* 
* why use smart pointer?
* to prevent following cases
* 1. memory leaks
* 2. double free bug
* 
* e.g. 
* 1. auto_ptr(dont use this anymore) -> allow copying -> make problems
* 2. unique_ptr -> alllow only move semantic: this one generated on stack
* 3. shared_ptr
*
* REMIND 
* Deepcopy vs. Shallow copy
* 1. Deepcopy -> copy all fields and allocate new memory to point
* 2. Shallow copy -> copy all fields leaving pointers point the original address
*
*/

#include <iostream>
#include <vector>

class A
{
public:
	
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
		delete [] data;
		data = nullptr;
		std::cout << "deallocated\n";
	}

	int* data = nullptr;
};

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

int main()
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

	// vector
	std::vector<std::unique_ptr<A>> v;
	v.emplace_back(new A); // simple way
	v.push_back(std::unique_ptr<A>(new A));

	// c++14
	auto pa2 = std::make_unique<A>();
	v.push_back(std::move(pa2));

	return 0;
}