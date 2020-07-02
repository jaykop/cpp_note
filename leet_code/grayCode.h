#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int> res;
        res.emplace_back(0);
        int next = 1;
        while (n--)
        {
            // double vector in rev
            res.insert(res.end(), res.rbegin(), res.rend());
            for (int i = next; i < res.size(); ++i)
                res[i] += next;
            next *= 2;
        }

        return res;
    }
};