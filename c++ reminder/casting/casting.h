#include <iostream>

class Parent
{
public:
	virtual void print()
	{
		std::cout << "I am Parent\n";
	}

	void unique_func()
	{
		std::cout << "This is parent's unique_func\n";
	}

};

class Child : public Parent
{
public:
	void print() override
	{
		std::cout << "I am Child\n";
	}

	void unique_func()
	{
		std::cout << "This is child's unique_func\n";
	}
};

void upcasting_and_downcasting()
{
	Parent* parent = new Parent;
	Child* child = new Child;

	// downcasting
	std::cout << "* downcasting *\n";
	std::cout << "downcasting Child to Parent\n";
	Parent* downcasted = static_cast<Parent*>(child);
	downcasted->print();
	downcasted->unique_func();

	std::cout << "\n";

	// upcasting
	std::cout << "* upcasting *\n";
	std::cout << "upcasting Parent to Child\n";
	Child* upcasted = static_cast<Child*>(parent);
	upcasted->print();
	upcasted->unique_func();

	delete parent;
	delete child;
}

void dynamic_casting()
{
	Parent* parent = new Parent;
	Child* child = new Child;
	Parent* parent2 = new Child;

	std::cout << "* dynamic casting *\n";
	std::cout << "casting Child to Parent\n";
	Parent* downcasted = dynamic_cast<Parent*>(child);
	if (downcasted)
	{
		downcasted->print();
		downcasted->unique_func();
	}
	else
		std::cout << "casted wrong\n";

	std::cout << "\n";

	std::cout << "casting Parent to Child\n";
	Child* upcasted1 = dynamic_cast<Child*>(parent2);
	if (upcasted1)
	{
		upcasted1->print();
		upcasted1->unique_func();
	}
	else
		std::cout << "casted wrong\n";

	std::cout << "\n";

	std::cout << "casting Parent to Child\n";
	Child* upcasted2 = dynamic_cast<Child*>(parent);
	if (upcasted2)
	{
		upcasted2->print();
		upcasted2->unique_func();
	}
	else
		std::cout << "casted wrong\n";

	delete parent2;
	delete parent;
	delete child;
}