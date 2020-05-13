#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        vector<vector<int>> diagonals;
        int m = int(mat.size());
        int n = int(mat[0].size());
        int min = m < n ? m : n;

        int l = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            vector<int> d;
            for (int j1 = 0, j2 = i; j2 < m && j1 < l; j1++, j2++)
                d.emplace_back(mat[j2][j1]);

            diagonals.emplace_back(d);
            l = l < min ? l + 1 : min;
        }

        l = n;
        for (int i = 1; i < n; i++)
        {
            vector<int> d;
            for (int j1 = i, j2 = 0; j2 < m && j1 < l; j1++, j2++)
                d.emplace_back(mat[j2][j1]);

            diagonals.emplace_back(d);
        }

        for (auto& d : diagonals)
            sort(d.begin(), d.end());

        l = 1;
        int thru = -1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j1 = 0, j2 = i; j2 < m && j1 < l; j1++, j2++)
                mat[j2][j1] = diagonals[m - 1 - i][j1];
            l = l < min ? l + 1 : min;
            thru++;
        }

        l = n;
        for (int i = 1; i < n; i++)
        {
            for (int j1 = i, j2 = 0; j2 < m && j1 < l; j1++, j2++)
                mat[j2][j1] = diagonals[i + thru][j2];
        }
        

        return mat;
    }
};