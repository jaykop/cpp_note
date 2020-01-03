#include "uniquePathsIII.h"

int main() {

	//Solution a;
	//vector<vector<int>> i = {{0, 1}, {2, 0}};
	//auto result = a.uniquePathsIII(i);

	int a = (1 ^ 4);
	int count = 0;
	while (a) {
		int bit = a % 2;
		if (bit) count++;
		a /= 2;
	}

	return 0;
}