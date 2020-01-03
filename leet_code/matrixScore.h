#pragma once
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:

    // convert from binary number to decimal
    int convert(const vector<int>& b) {

        int sum = 0; //return value
        int size = int(b.size());
        int mul = 1;
        // convert
        for (int i = size - 1; i >= 0; i--) {
            // if the i-th index is 1, 
            // add the value
            if (b[i]) sum += mul;
            mul *= 2;
        }

        return sum;
    }

    // get the sum of matrix
    int get_sum(vector<vector<int>>& m) {

        int sum = 0;
        // for each row, convert the binary
        // and sum up of those
        for (const auto& r : m)
            sum += convert(r);

        return sum;
    }

    // greedy_dfs
    // not operate when given parameter is -1
    void greedy_dfs(int r, int c, // row/col to flip
        int size_r, int size_c, // len of row/col
        vector<vector<int>> m, // m to flip
        int& last_max) {

        if (r >= 0) {
            for (int i = 0; i < size_c; i++)
                m[r][i] = !m[r][i];
        }

        else if (c >= 0) {
            for (int i = 0; i < size_r; i++)
                m[i][c] = !m[i][c];
        }

        // get sum
        int sum = get_sum(m);
        if (last_max < sum) {
            last_max = sum;
            for (int i = 0; i < size_r; i++)
                greedy_dfs(i, -1, size_r, size_c, m, last_max);
            for (int i = 0; i < size_c; i++)
                greedy_dfs(-1, i, size_r, size_c, m, last_max);
        }
    }

    int matrixScore(vector<vector<int>>& A) {

        int last_max = -1; // 
        int size_r = int(A.size());
        int size_c = int(A[0].size());

        greedy_dfs(-1, -1, size_r, size_c, A, last_max);

        return last_max;
    }
};

// best answer...
//class Solution {
//public:
//    int matrixScore(vector<vector<int>>& A) {
//        int r = A.size();
//        int c = A[0].size();
//        int rowflip[r];
//        memset(rowflip, -1, sizeof(rowflip));
//        for (int i = 0; i < r; i++)
//        {
//            if (A[i][0] == 0) rowflip[i] = 1;
//        }
//        int ans = 0, p = 1, count = 0;
//        for (int j = c - 1; j >= 0; j--)
//        {
//            count = 0;
//            for (int i = 0; i < r; i++)
//            {
//                if (rowflip[i] == 1) count += (A[i][j] ^ 1);
//                else count += A[i][j];
//            }
//            ans += p * max(count, r - count);
//            p *= 2;
//        }
//        return ans;
//    }
//};