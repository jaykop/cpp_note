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
            // check if the agent walk over every empty sq
            else if (grid[current_y][current_x] == 2
                && match_size == walks) {

                // increase the number of path
                num_path++;
            }
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

// JAVA DP code answer...
//class Solution {
//    int ans;
//    int[][] grid;
//    int R, C;
//    int tr, tc, target;
//    int[] dr = new int[] {0, -1, 0, 1};
//    int[] dc = new int[] {1, 0, -1, 0};
//    Integer[][][] memo;
//
//    public int uniquePathsIII(int[][] grid) {
//        this.grid = grid;
//        R = grid.length;
//        C = grid[0].length;
//        target = 0;
//
//        int sr = 0, sc = 0;
//        for (int r = 0; r < R; ++r)
//            for (int c = 0; c < C; ++c) {
//                if (grid[r][c] % 2 == 0)
//                    target |= code(r, c);
//
//                if (grid[r][c] == 1) {
//                    sr = r;
//                    sc = c;
//                }
//                else if (grid[r][c] == 2) {
//                    tr = r;
//                    tc = c;
//                }
//            }
//
//        memo = new Integer[R][C][1 << R * C];
//        return dp(sr, sc, target);
//    }
//
//    public int code(int r, int c) {
//        return 1 << (r * C + c);
//    }
//
//    public Integer dp(int r, int c, int todo) {
//        if (memo[r][c][todo] != null)
//            return memo[r][c][todo];
//
//        if (r == tr && c == tc) {
//            return todo == 0 ? 1 : 0;
//        }
//
//        int ans = 0;
//        for (int k = 0; k < 4; ++k) {
//            int nr = r + dr[k];
//            int nc = c + dc[k];
//            if (0 <= nr && nr < R && 0 <= nc && nc < C) {
//                if ((todo & code(nr, nc)) != 0)
//                    ans += dp(nr, nc, todo ^ code(nr, nc));
//            }
//        }
//        memo[r][c][todo] = ans;
//        return ans;
//    }
//}