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
        // convert
        for (int i = 0; i < size; i++) {
            // if the i-th index is 1, 
            // add the value
            if (b[i]) sum += int(std::powf(2, size-i-1));
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