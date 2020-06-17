#pragma once
#include <vector>

using namespace std;

// 

// found answer
class Solution {
public:

    bool canJump(vector<int>& nums) {

        int size = int(nums.size());
        int dest = size - 1;
        for (int i = size - 2; i >= 0; --i)
        {
            if (nums[i] >= dest - i)
                dest = i;
        }
        if (dest == 0)
            return true;

        return false;
    }
};

// not good solution
class Solution {
public:

    bool dfs(const vector<int>& nums,
        int index)
    {
        if (index >= nums.size() - 1)
            return true;

        bool res = false;
        for (int i = nums[index]; i > 0; --i)
        {
            res = dfs(nums, index + i);
            if (res) break;
        }

        return res;
    }

    bool canJump(vector<int>& nums) {

        return dfs(nums, 0);
    }
};