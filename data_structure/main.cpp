#include <iostream>
#include "vector.h"
#include "list.h"

#include <vector>
#include <list>

// using namespace std;

void test_vector()
{
	vector<int> a;

	std::cout << "Test push back\n";
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test pop back\n";
	for (int i = 0; i < 5; i++)
		a.pop_back();
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test reverse iterator\n";
	for (auto rit = a.rbegin(); rit != a.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << "\n";

	std::cout << "Test resize - increment\n";
	a.resize(20, 1);
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test resize - decrement\n";
	a.resize(10, 1);
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test reserve - increment\n";
	a.reserve(30);
	for (int i = 0; i < 20; i++)
		a.push_back(i);
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test reserve - decrement\n";
	a.reserve(10);
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test clear\n";
	a.clear();
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

void test_list()
{
	list<int> a, b;

	std::cout << "Test push back\n";
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	std::cout << "a: ";
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	for (int i = 10; i < 20; i++)
		b.push_back(i);
	std::cout << "\nb: ";
	for (auto it = b.begin(); it != b.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test merge\n";
	a.merge(b);
	std::cout << "a: ";
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\nb: ";
	//for (auto it = b.begin(); it != b.end(); ++it)
	//	std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test pop back\n";
	for (int i = 0; i < 5; i++)
		a.pop_back();
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << "Test reverse iterator\n";
	for (auto rit = a.rbegin(); rit != a.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << "\n";

	////std::cout << "Test resize - increment\n";
	////a.resize(20, 1);
	////for (int i = 0; i < 10; i++)
	////	a.push_back(i);
	////for (auto it = a.begin(); it != a.end(); ++it)
	////	std::cout << *it << " ";
	////std::cout << "\n";

	////std::cout << "Test resize - decrement\n";
	////a.resize(10, 1);
	////for (auto it = a.begin(); it != a.end(); ++it)
	////	std::cout << *it << " ";
	////std::cout << "\n";

	std::cout << "Test insert\n";
	a.insert(a.begin(), 100);
	a.insert(a.begin() + 5, 200);
	a.insert(a.end(), 200);
	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
	// 100 0 1 2 3 200 4 5 ... 200
	std::cout << "\n";

	std::cout << "Test clear\n";
	a.clear();

	// a.erase();
}

int main(void) {

	std::vector<int> a;
	a.reserve(10);

	// test_vector();
	//test_list();

	return 0;
}