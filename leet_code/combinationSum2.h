#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> res;

    void collapse(const vector<int>& nums,
        vector<int> v,
        int target, int index)
    {
        if (!target)
        {
            res.emplace_back(v);
            return;
        }

        for (int i = index; i < nums.size() && nums[i] <= target; ++i)
        {
            v.emplace_back(nums[i]);
            collapse(nums, v, target - nums[i], i + 1);
            v.pop_back();

            while (i + 1 < nums.size()
                && nums[i] == nums[i + 1])
                ++i;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        std::vector<int> v;
        collapse(nums, v, target, 0);

        return res;
    }
};