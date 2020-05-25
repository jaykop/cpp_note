#include "LRUCache.h"

int main() {

	//vector<int> v =	{ 2, 3, 4, 5, 18, 17, 6 };
	//Solution a;
	//auto b = a.maxArea(v);

	LRUCache cache = LRUCache(2 /* capacity */);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4

	return 0;
}