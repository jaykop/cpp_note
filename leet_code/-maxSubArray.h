#pragma once
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {

public:

    int maxSubArray(vector<int>& nums) {

        int ans = nums.front(), sum = 0;
        int n = int(nums.size());
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
};
