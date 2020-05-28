#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty())
            return 0;

        int res = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[res] < nums[i])
            {
                ++res;
                swap(nums[res], nums[i]);
            }

        return res;
    }
};