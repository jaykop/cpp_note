#pragma once
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:


    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> cnt(m, grid[0][0]);
        for (int i = 1; i < m; ++i)
            cnt[i] = cnt[i - 1] + grid[i][0];

        for (int j = 1; j < n; ++j)
        {
            cnt[0] += grid[0][j];
            for (int i = 1; i < m; ++i)
                cnt[i] = min(cnt[i], cnt[i-1]) + grid[i][j];
        }

        return cnt[m - 1];
    }
};