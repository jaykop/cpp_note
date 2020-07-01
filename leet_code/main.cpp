#include "merge_easy.h"
#include <iostream>

int main() {

	Solution a;
	vector<int> v1 = { 2, 2, 3, 0, 0, 0 };
	vector<int> v2 = { 2, 5, 6 };

	a.merge(v1, 3, v2, 3);

	return 0;
}