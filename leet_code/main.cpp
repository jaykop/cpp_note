#include "maxIncreaseKeepingSkyline.h"

int main() {

	Solution a;
	vector<vector<int>> grid = { {3, 0, 8, 4},{2, 4, 5, 7},{9, 2, 6, 3},{0, 3, 1, 0} };
	auto result = a.maxIncreaseKeepingSkyline(grid);

	return 0;
}