#pragma once
#include <vector>
#include <set>
using namespace std;
class Solution {
public:

    int setSum(int val) {
        if (val) return 1;
        return -1;
    }

    int dfs(vector<vector<int>> m,
        set<pair<int, int>> log,
        int num_flipped, int sum,
        int row, int col,
        int size_r, int size_c) {

        log.erase({ row, col });

        m[row][col] = !m[row][col];
        sum += setSum(m[row][col]);
        if (row + 1 < size_r) {
            m[row + 1][col] = !m[row + 1][col];
            sum += setSum(m[row + 1][col]);
        }
        if (row - 1 >= 0) {
            m[row - 1][col] = !m[row - 1][col];
            sum += setSum(m[row - 1][col]);
        }
        if (col + 1 < size_c) {
            m[row][col + 1] = !m[row][col + 1];
            sum += setSum(m[row][col + 1]);
        }
        if (col - 1 >= 0) {
            m[row][col - 1] = !m[row][col - 1];
            sum += setSum(m[row][col - 1]);
        }

        if (!sum)
            return num_flipped;

        // else
        // do flip
        int toReturn = -1;
        for (const auto& p : log) {
            toReturn = dfs(m, log,
                num_flipped + 1, sum,
                get<0>(p), get<1>(p),
                size_r, size_c);
            if (toReturn != -1) break;
        }

        return toReturn;
    }

    int minFlips(vector<vector<int>>& mat) {

        set<pair<int, int>> log;

        int size_c = int(mat[0].size());
        int size_r = int(mat.size());
        int sum = 0;

        for (int i = 0; i < size_r; i++) {
            for (int j = 0; j < size_c; j++) {
                log.insert({ i, j });
                if (mat[i][j]) sum += 1;
            }
        }

        if (!sum) return 0;

        int toReturn = -1;
        for (const auto& p : log) {
            toReturn = dfs(mat, log,
                1, sum,
                get<0>(p), get<1>(p),
                size_r, size_c);
            if (toReturn != -1) break;
        }

        return toReturn;
    }
};