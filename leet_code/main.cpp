#include "LRUCache.h"
#include <iostream>
int main() {

	//vector<int> v =	{ 2, 3, 4, 5, 18, 17, 6 };
	//Solution a;
	//auto b = a.maxArea(v);

	LRUCache cache = LRUCache(2 /* capacity */);

	cache.put(1, 1);
	cache.put(2, 2);
	std::cout << cache.get(1) << "\n";       // returns 1
	cache.put(3, 3);    // evicts key 2
	std::cout << cache.get(2) << "\n";       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	std::cout << cache.get(1) << "\n";       // returns -1 (not found)
	std::cout << cache.get(3) << "\n";       // returns 3
	std::cout << cache.get(4) << "\n";       // returns 4

	//cache.put(2, 1);
	//std::cout << cache.get(2) << "\n";       // returns 1
	//std::cout << cache.get(2) << "\n";       // returns -1 (not found)
	//std::cout << cache.get(3) << "\n";       // returns -1 (not found)


	return 0;
}