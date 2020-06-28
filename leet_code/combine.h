#pragma once
#include <vector>
#include <queue>

using namespace std;

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

// even worse
class Solution {
public:

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;

        deque<vector<int>> dq;
        for (int i = 1; i <= n; ++i)
        {
            vector<int> v{ i };
            dq.push_back(v);
        }

        while (!dq.empty())
        {
            auto v = dq.front();
            dq.pop_front();

            if (v.size() == k)
                res.push_back(v);

            else
            {
                for (int i = v.back() - 1; i > 0; --i)
                {
                    v.push_back(i);
                    dq.push_back(v);
                    v.pop_back();
                }
            }
        }

        return res;
    }
};