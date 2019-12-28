#pragma once
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {

		map<int, int> table, table2;
		for (auto i : arr)
			table[i]++;
		for (auto t : table) {
			table2[t.second]++;
			if (table2[t.second] == 2) {
				return false;
			}
		}

		return true;
	}
};