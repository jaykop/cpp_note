#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res;
        int count = 0;
        bool toggle = false;

        for (auto& i : nums)
        {
            if (i == target)
            {
                if (!toggle)
                {
                    toggle = true;
                    res.push_back(count);
                }
            }
            else
            {
                if (toggle)
                {
                    toggle = false;
                    res.push_back(count - 1);
                    break;
                }
            }
            count++;
        }
        if (res.empty())
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        else if (res.size() == 1)
        {
            if (toggle)
                res.push_back(count - 1);
            else
                res.push_back(res[0]);
        }
        return res;
    }
};