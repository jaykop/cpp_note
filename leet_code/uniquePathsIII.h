#pragma once
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& grid,
        int walks, int match_size,
        int row_size, int col_size,
        int current_x, int current_y,
        int& num_path) {

        // if the tile is valid,
        if (row_size > current_y && col_size > current_x
            && current_x >= 0 && current_y >= 0) {

            // if the current one is empty,
            // spread to next nodes
            if (grid[current_y][current_x] == 0
                || grid[current_y][current_x] == 1) {

                int temp = grid[current_y][current_x];

                // leave a mark that visited
                grid[current_y][current_x] = 3;

                dfs(grid, walks + 1, match_size,
                    row_size, col_size,
                    current_x + 1, current_y,
                    num_path);
                dfs(grid, walks + 1, match_size,
                    row_size, col_size,
                    current_x, current_y + 1,
                    num_path);
                dfs(grid, walks + 1, match_size,
                    row_size, col_size,
                    current_x - 1, current_y,
                    num_path);
                dfs(grid, walks + 1, match_size,
                    row_size, col_size,
                    current_x, current_y - 1,
                    num_path);

                grid[current_y][current_x] = temp;
            }

            // if the current one is the destination,
            else if (grid[current_y][current_x] == 2) {

                // check if the agent walk over every empty sq
                if (match_size == walks) {

                    // increase the number of path
                    num_path++;
                }

            }

            // if the current one is obstacle,
            // or already visited
            // if (grid[current_y][current_x] == -1
            //    || grid[current_y][current_x] == 3)
            /*else
                return;*/
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        //lets do dfs way first...

        int row_size = int(grid.size());
        int col_size = int(grid[0].size());
        int total_size = row_size * col_size;
        int start_x = 0, start_y = 0;
        int obs = 0;

        // count the num of obstacles
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == -1)
                    obs++;
                else if (grid[i][j] == 1) {
                    start_x = j;
                    start_y = i;
                }
            }
        }

        int match_size = total_size - obs - 1;
        int num_path = 0;
        dfs(grid, 0, match_size,
            row_size, col_size,
            start_x, start_y,
            num_path);

        return num_path;
    }
};