#include "countGoodTriplets.h"
#include <iostream>

int main() {

	Solution a;
	vector<int> v = { 7, 3, 7, 3, 12, 1, 12, 2, 3 };
	auto i = a.countGoodTriplets(v, 5, 8, 1);

	return 0;
}