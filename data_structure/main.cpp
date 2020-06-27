#include <iostream>
#include "vector.h"
// #include <vector>

using namespace std;

int main(void) {

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

	return 0;
}