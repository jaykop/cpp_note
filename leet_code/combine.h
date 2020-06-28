#pragma once
// not a good solution
class Solution {
public:

    void add(vector<vector<int>>& v,
        vector<int> given,
        int n, int k)
    {
        for (int i = n; i > 0; --i)
        {
            given.emplace_back(i);
            if (given.size() == k)
                v.emplace_back(given);
            else
                add(v, given, i - 1, k);

            given.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> v;
        add(res, v, n, k);
        return res;
    }
};