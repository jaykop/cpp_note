#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {

        // 
        vector<vector<int>> mat;
        for (int v = 0; v < n; v++) {
            vector<int> row(m, 0);
            mat.push_back(row);
        }
        for (const auto& i : indices) {

            for (int c = 0; c < m; c++)
                mat[i[0]][c]++;
            for (int r = 0; r < n; r++)
                mat[r][i[1]]++;
        }

        int odds = 0;
        for (int c = 0; c < m; c++) {
            for (int r = 0; r < n; r++)
                if (mat[r][c] % 2)
                    odds++;
        }
        return odds;
    }
};