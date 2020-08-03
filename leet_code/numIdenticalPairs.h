#pragma once
#include <vector>
#include <map>
using namespace std;
class Solution {
public:

    int numIdenticalPairs(vector<int>& nums) {

        int ans = 0;
        map<int, int> table; // val and index
        int size = int(nums.size());
        for (int i = 0; i < size; ++i)
        {
            table[nums[i]]++;
        }

        for (const auto& t : table)
        {
            if (t.second > 1)
                ans += t.second * (t.second - 1) / 2;
        }

        return ans;
    }
};