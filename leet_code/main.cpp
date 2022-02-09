#include "combinationSum.h"
#include <iostream>

int cut_rod(vector<int>& table, int n)
{
	if (n == 0) // no more to cut
		return 0;

	int q = INT_MIN; // lower bound

	for (int i = 1; i <= n; ++i)
		// updating q adding max value so far
		q = max(q, table[i] + cut_rod(table, n - i));

	return q;
}

int main() {

	Solution s;
	vector<int> v = { 1,2 };
	auto res = s.combinationSum(v, 1);

	// simple dp practice
	//vector<int> table = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

	//auto ans = cut_rod(table, 4);
		
	//Solution a;
	//vector<vector<int>> v
	//	=
	//{
	//	{-10}
	//};

	//auto i = a.minimumTotal(v);

	return 0;
}	