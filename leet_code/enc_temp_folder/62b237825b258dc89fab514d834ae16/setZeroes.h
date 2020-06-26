#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int max_r = int(matrix.size());
        int max_c = int(matrix[0].size());
        int count = max_r * max_c;

        vector<pair<int, int>> index;

        while (count)
        {
            int r = (count - 1) / max_c;
            int c = (count - 1)  % max_c;
            if (matrix[r][c] == 0)
                index.emplace_back(pair<int, int>(r, c));

            --count;
        }

        while (!index.empty())
        {
            auto p = index.back();
            if (!matrix[p.first][p.second])
            {
                for (int i = max_r - 1; i >= 0; --i)
                    matrix[i][p.second] = 0;
                for (int j = max_c - 1; j >= 0; --j)
                    matrix[p.first][j] = 0;
            }

            index.pop_back();
        }
    }
};