#include "uniquePathsWithObstacles.h"
#include <iostream>

int main() {

	Solution a;
	vector<vector<int>> v
		=
	{
		{0,0},
		{1,1},
		{0,0}
	};

	auto i = a.uniquePathsWithObstacles(v);

	return 0;
}