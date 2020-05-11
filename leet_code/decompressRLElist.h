#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {

        vector<int> toReturn;
        int size = int(nums.size()), freq = -1;

        for (int i = 0; i < size; i++) {

            if (i % 2) {
                for (int j = 0; j < freq; j++)
                    toReturn.push_back(nums[i]);
            }

            else freq = nums[i];
        }

        return toReturn;

    }
};