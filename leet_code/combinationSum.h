#pragma once
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    unordered_set<int> table;

    void collapse(int target, )
    {
        for (auto i : table)
        {
            int rest = target - i;
            if (table.find(rest) != table.end())
            {
                std::vector<int> sub;
                sub.push_back(rest);
                sub.push_back(i);
                res.push_back(sub);
            }
            collapse(rest, );
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        for (auto i : nums)
            table.insert(i);

        collapse(target, nums);

        //          int size = int(nums.size());
        //          while (i < j)
        //          {
        //              int i = 0, j = size;
        //              while (nums[j] >= target)
        //                  j--;
        //              if (nums[j+1] == target)
        //                  res.push_back({target});

        //              i++;
        //          }

        return res;
    }
};