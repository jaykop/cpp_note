#include "spiralOrder.h"
#include <iostream>

int main() {

	Solution a;
	vector<vector<int>> v = 
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }

		//{1, 2, 3, 4},
  //{5, 6, 7, 8},
  //{9,10,11,12}
	};
	
	auto i = a.spiralOrder(v);

	return 0;
}