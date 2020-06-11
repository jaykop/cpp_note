#pragma once
#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool decrementing(const vector<int>& v)
    {
        for (int i = 0; i + 1 < v.size(); ++i)
            if (v[i] < v[i + 1])
                return false;

        return true;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.emplace_back(nums);

        if (nums.size() > 1)
        {
            while (!decrementing(nums))
            {
                int k = -1;
                int offset = -1, smallest = -1;
                int size = nums.size();
                for (int i = size - 1; i >= 0 && i < size; i += offset)
                {
                    // find first a_k < a_k+1
                    if (offset == -1 &&
                        i + 1 < size &&
                        nums[i] < nums[i + 1])
                    {
                        k = i;
                        offset = 1;
                        smallest = k + 1;
                    }

                    // get tail
                    else if (offset == 1)
                    {
                        if (nums[k] < nums[i] && nums[i] < nums[smallest])
                            smallest = i;
                    }
                }

                swap(nums[smallest], nums[k]);
                sort(nums.begin() + k + 1, nums.end());

                res.emplace_back(nums);
            }
        }

        return res;
    }
};