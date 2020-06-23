#include "getPermutation.h"
#include <iostream>

int main() {

	Solution a;
	string b = "1234567890";
	b = b.substr(3, 3); // 456
	auto i = a.getPermutation(4, 9);

	return 0;
}