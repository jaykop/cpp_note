#include <iostream>
#include "vector.h"
// #include <vector>

using namespace std;

int main(void) {

	vector<int> a(10, 0);
	for (int i = 0; i < a.size(); i++) {
		a[i] = i;
		std::cout << a[i] << " ";
	}
	auto end = a.end();
	auto back = a.back();
	auto front = a.front();
	auto c = a.capacity();
	a.clear();
	c = a.capacity();
	return 0;
}