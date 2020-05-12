#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        int size = int(nums.size());
        vector<int> toReturn;

        for (int i = 0; i < size; i++)
        {
            toReturn.insert(toReturn.begin() + index[i], nums[i]);
        }

        return toReturn;
    }
};