#pragma once
#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() ||
            matrix[0].empty() ||
            target < matrix[0][0])
            return false;

        int max_r = matrix.size() - 1;
        int max_c = matrix[0].size() - 1;
        int i = 0;

        for (; i <= max_r; ++i)
        {
            if (target <= matrix[i][max_c])
            {
                for (auto n : matrix[i])
                    if (n == target)
                        return true;
            }

            else if (target < matrix[i][0])
            {
                --i;
                for (auto n : matrix[i])
                    if (n == target)
                        return true;
            }
        }

        return false;
    }
};