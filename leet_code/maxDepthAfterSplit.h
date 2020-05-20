#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> res;
        int count = 1;
        bool last_was_left = false;
        for (auto i : seq)
        {
            if (i == '(')
            {
                if (last_was_left)
                    count++;
                last_was_left = true;
            }
            else
            {
                if (!last_was_left)
                    count--;
                last_was_left = false;
            }

            res.emplace_back(count % 2);
        }

        return res;
    }
};