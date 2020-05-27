#pragma once
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;

        map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
            table[i]++;

        for (int i = 0; i < nums.size(); i++)
        {
            if (table[i] > 0)
            {
                for (int j = i + 1; j < nums.size() - 1; j++)
                {
                    int third = -(nums[j] + nums[i]);
                    auto found = find(nums.begin(), nums.end(), third);
                    int k = distance(nums.begin(), found);
                    if (found != nums.end()
                        && i != k && j != k)
                    {
                        table[i]--;
                        table[j]--;
                        table[k]--;
                        vector<int> sum;
                        sum.push_back(nums[i]);
                        sum.push_back(nums[j]);
                        sum.push_back(third);
                        res.push_back(sum);
                    }
                }
            }
        }

        return res;
    }
};