#pragma once
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:

    int getKth(int lo, int hi, int k) {

        if (lo == hi)
            return lo;

        vector<pair<int, int>> res;
        for (int i = lo; i <= hi; i++)
        {
            int n = i;
            int count = 0;
            while (n > 1) {
                // odd
                if (n % 2)
                    n = 3 * n + 1;//(n << 1) + n + 1;


                // even
                else
                    n = n / 2;//n >> 1;

                count++;
            }

            std::pair<int, int> p(count, i);
            res.emplace_back(p);
        }

        std::sort(res.begin(), res.end());

        return res[k - 1].second;
    }
};