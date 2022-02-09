#pragma once
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        queue<vector<int>> cq;

        for (auto i : candidates)
        {
            vector<int> v;
            v.push_back(i);
            if (i != target)
                v.push_back(i);
            cq.push(v);
        }

        vector<vector<int>> res;
        while (!cq.empty())
        {
            for (auto i : candidates)
            {
                vector<int> cv = cq.front();
                int last = cv.back();
                int sum = last + i;

                cv.pop_back();
                if (cv.empty() || cv.back() > i) continue;
                else if (sum == target)
                {
                    cv.push_back(i);
                    res.push_back(cv);
                }
                else if (sum < target && target - sum >= i)
                {
                    cv.push_back(i);
                    cv.push_back(sum);
                    cq.push(cv);
                }
            }
            cq.pop();
        }


        return res;
    }
};