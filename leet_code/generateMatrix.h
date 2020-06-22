#pragma once
#include <vector>

using namespace std;

class Solution {
public:

    void fillMatrix(vector<vector<int>>& mat,
        int size) 
    {
        int num = 0;
        int count = size, offset = 0;
        int total = size * size;
        int r = 0, c = 0;
        int status = 0; // 0 ~ 3

        while (total)
        {
            mat[r][c] = ++num;
            --total;
            --count;

            if (count == 0)
            {
                if (status % 4 != 1 && status % 4 != 3)
                    ++offset;

                ++status;
                count = size - offset;
            }

            switch (status % 4)
            {
            case 0: ++c; break;
            case 1: ++r; break;
            case 2: --c; break;
            case 3: --r; break;
            }
        }
    }

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n);

        // generate matrix
        for (auto& r : ans)
        for (int i = 0; i < n; ++i)
            r.emplace_back(-1);

        fillMatrix(ans, n);

        return ans;
    }
};