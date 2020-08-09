#pragma once
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> res;

    void collapse(const vector<int>& nums, int target, 
        vector<int>& v, int index)
    {
        if (!target)
        {
            res.emplace_back(v);
            return;
        }

		for (int i = index; i < nums.size() && nums[i] <= target; ++i)
		{
			v.emplace_back(nums[i]);
			collapse(nums, target - nums[i], v, i);
			v.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        std::vector<int> v;
        collapse(nums, target, v, 0);

        return res;
    }
};