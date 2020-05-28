#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {

        std::sort(nums.begin(), nums.end());
        
        int size = int(nums.size());
        int res = nums[0];

        for (auto i : nums)
        {
            if (target - res > target - i)
                res = i;
        }

        int mid = size / 2;

        
        //for (unsigned i = 0; i < nums.size() - 2; i++)
        //{
        //    for (unsigned j = i + 1; j < nums.size() - 1; j++)
        //    {
        //        for (unsigned k = j + 1; k < nums.size(); k++)
        //        {
        //            int sum = nums[i] + nums[j] + nums[k];
        //            if (abs(sum - target) < abs(res - target))
        //                res = sum;
        //        }
        //    }
        //}

        return res;
    }
};