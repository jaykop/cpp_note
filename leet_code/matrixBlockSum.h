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

//class Solution {
//public:
//    int sizeX, sizeY;
//    int getSum(int i, int j, vector<vector<int>>& sum)
//    {
//        if (i < 0 || j < 0) return 0;
//        if (i >= sizeX) i = sizeX - 1;
//        if (j >= sizeY) j = sizeY - 1;
//        return sum[i][j];
//    }
//
//    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
//        sizeX = mat.size();
//        sizeY = mat[0].size();
//        int size = sizeX * sizeY;
//        vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));
//
//        for (int it = 0; it < size; it++)
//        {
//            int i = it / sizeY;
//            int j = it % sizeY;
//            sum[i][j] = mat[i][j] + getSum(i - 1, j, sum) + getSum(i, j - 1, sum)
//                - getSum(i - 1, j - 1, sum);
//        }
//
//        vector<vector<int>> ans(sizeX, vector<int>(sizeY, 0));
//        for (int it = 0; it < size; it++)
//        {
//            int i = it / sizeY;
//            int j = it % sizeY;
//            ans[i][j] = getSum(i + K, j + K, sum) + getSum(i - K - 1, j - K - 1, sum)
//                - getSum(i - K - 1, j + K, sum) - getSum(i + K, j - K - 1, sum);
//        }
//
//        return ans;
//    }
//};