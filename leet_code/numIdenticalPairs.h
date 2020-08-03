#pragma once
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

    int numIdenticalPairs(vector<int>& nums) {

        int ans = 0;
        map<int, vector<int>> table; // val and index
        int size = int(nums.size());
        for (int i = 0; i < size; ++i)
        {
            auto found = table.find(nums[i]);
            if (found == table.end())
            {
                vector<int> list;
                list.push_back(i);
                table.insert({ nums[i], list });
            }
            else
            {
                found->second.push_back(i);
            }
        }

        for (const auto& t : table)
        {
            int t_size = int(t.second.size());
            if (t_size > 1)
                ans += t_size * (t_size - 1) / 2;
        }

        return ans;
    }
};