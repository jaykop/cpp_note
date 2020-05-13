#pragma once
#include <vector>

using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int count = 0, neg_row = 0;
        int grid_size = int(grid.size());
        int row_size = int(grid[0].size());
        for (int i = grid_size - 1; i >= 0; i--) {
            if (grid[i][0] < 0)
                neg_row++;

            else {
                for (int j = row_size - 1; j >= 0; j--)
                    if (grid[i][j] < 0)
                        count++;
                    else
                        break;
            }
        }
        return count + neg_row * row_size;
    }
};