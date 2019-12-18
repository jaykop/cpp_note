#pragma once
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        // get len
        int col_len = int(grid.size());
        int row_len = int(grid[0].size());
        vector<int> row_list, col_list;

        // lets loop thru each row
        for (int i = 0; i < col_len; i++) {

            int largest_row = grid[i][0];
            // lets loop thru each element
            for (int j = 0; j < row_len; j++) {
                
                // update the largest row val
                if (grid[i][j] > largest_row)
                    largest_row = grid[i][j];

                // update largest col val
                if (int(col_list.size()) != col_len)
                    col_list.push_back(grid[i][j]);

                else if (grid[i][j] > col_list[j])
                    col_list[j] = grid[i][j];
            }

            row_list.push_back(largest_row);
        }

        // get sum of diff here
        int sum = 0;
        for (int i = 0; i < col_len; i++) {

            for (int j = 0; j < row_len; j++) {

                sum += std::min(std::max(grid[i][j], col_list[j]), std::max(grid[i][j], row_list[i])) - grid[i][j];
            }
        }

        return sum;
    }
};