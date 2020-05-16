#include "luckyNumbers.h"

int main() {

	vector<vector<int>> m =
		//{ 
		//	{3, 7, 8},
		//	{9, 11, 13},
		//	{15, 16, 17}
		//};
	{ 
		{1, 10, 4, 2}, 
		{9, 3, 8, 7}, 
		{15, 16, 17, 12} };
		
		Solution a;
	auto b = a.luckyNumbers(m);

	return 0;
}