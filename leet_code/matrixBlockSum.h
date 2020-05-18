#pragma once
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {

        // unordered_map<unordered_map<int>, int> table;
        vector<vector<int>> res = mat;
        int r_size = mat.size();
        int c_size = mat[0].size();

        // iterate whole mat
        // most simple way
        for (int i = 0; i < r_size; i++)
        {
            for (int j = 0; j < c_size; j++)
            {
                int sum = 0;
                for (int r = i - K; r <= i + K && r < r_size; r++)
                {
                    for (int c = j - K; c <= j + K && c < c_size; c++)
                    {
                        if (0 <= r && 0 <= c)
                            sum += mat[r][c];
                    }
                }
                res[i][j] = sum;
            }
        }

        return res;
    }
};