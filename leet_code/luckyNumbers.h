#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        // get the lowest numbers from each row
        vector<int> lowests, luckyNums;
        int m = matrix.size(), n = matrix[0].size();

        for (int r1 = 0; r1 < m; r1++)
        {
            int lowest = numeric_limits<int>::max();
            int lowest_c = -1;
            for (int c = 0; c < n; c++)
            {
                if (matrix[r1][c] < lowest) {
                    lowest = matrix[r1][c];
                    lowest_c = c;
                }
            }

            bool add = true;
            for (int r2 = 0; r2 < m; r2++)
            {
                if (lowest < matrix[r2][lowest_c])
                {
                    add = false;
                    break;
                }
            }

            if (add)
                luckyNums.emplace_back(lowest);
        }

        return luckyNums;
    }
};