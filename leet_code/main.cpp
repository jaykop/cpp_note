#include "countAndSay.h"
#include <iostream>
int main() {
		
	Solution a;
	for (int i = 4; i < 10; i++)
	{
		auto ans = a.countAndSay(i);
		std::cout << ans <<	std::endl;
	}

	return 0;
}