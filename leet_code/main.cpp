#include "merge.h"
#include <iostream>

int main() {

	Solution a;
	vector<vector<int>> v = 
	{
		///*{1,4}, {0,4}*/{1,4},{4,5}/*{1,3} ,{2,6},{8,10},{15,18}*/
		/*{1,4}, {0,2}, {3,5}*/
		{2,3},{4,6},{5,7},{3,4}
	};
	
	auto i = a.merge(v);

	return 0;
}