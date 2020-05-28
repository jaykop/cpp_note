#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if (nums.empty())
            return 0;

        int res = 0;
        while (nums[res] != val)
            res++;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                swap(nums[res], nums[i]);
                res++;
            }
        }

        return res;
    }
};