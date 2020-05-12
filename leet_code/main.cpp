#include "createTargetArray.h"

int main() {

	vector<int> nums = { 0, 1, 2, 3, 4 },
		index = { 0, 1, 2, 2, 1 };
	Solution a;
	auto result = a.createTargetArray(nums, index);

	return 0;
}