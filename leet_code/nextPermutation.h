#pragma once
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if (nums.empty() || nums.size() == 1)
            return;
        if (nums.size() == 2)
        {
            swap(nums[0], nums[1]);
            return;
        }
        int size = int(nums.size());
        int index = -1;
        for (int i = size - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int a_k = INT_MAX, k = -1;
        for (int i = size - 1; i > index; i--)
        {
            if (nums[i] < a_k && nums[index] < nums[i])
            {
                a_k = nums[i];
                k = i;
            }
        }
        if (k == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        nums.erase(nums.begin() + k);
        nums.insert(nums.begin() + index, a_k);
        sort(nums.begin() + index + 1, nums.end());
    }
};