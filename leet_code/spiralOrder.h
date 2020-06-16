#pragma once
#include <vector>
using namespace std;

class Solution {
public:

    void read(vector<int>& cnt,
        vector<vector<int>>& matrix,
        int r, int c, int size,
        bool update_row, bool increase)
    {
        while (size)
        {
            cnt.push_back(matrix[r][c]);
            if (update_row)
            {
                if (increase)
                    r++;
                else r--;
            }
            else
            {
                if (increase)
                    c++;
                else c--;
            }
            size--;
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> cnt;
        if (matrix.empty())
            return cnt;

        // the size is n x n;
        int n = int(matrix.size());
        int m = matrix[0].size();
        unsigned total = m * n;

        for (int i = 0; cnt.size() < total; )
        {
            read(cnt, matrix, i, i, m - i * 2, false, true);
            if (cnt.size() == total)
                break;
            read(cnt, matrix, i + 1, m - i - 1, n - i * 2 - 1, true, true);
            if (cnt.size() == total)
                break;
            read(cnt, matrix, n - i - 1, m - i - 2, m - i * 2 - 1, false, false);
            if (cnt.size() == total)
                break;
            read(cnt, matrix, n - i - 2, i, n - i * 2 - 2, true, false);
            if (cnt.size() == total)
                break;

            ++i;
        }

        return cnt;
    }
};