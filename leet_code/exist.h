#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool check_neighbor(vector<vector<char>>& board,
        int r, int c, int m, int n,
        const string& word, int index)
    {
        if (index + 1 == word.length())
            return true;

        char tmp = board[r][c];
        board[r][c] = '.';

        for (int i = -1; i < 2; ++i)
        {
            for (int j = -1; j < 2; ++j)
            {
                int x = r + i;
                int y = c + j;
                if (unsigned(x) < unsigned(m) &&
                    unsigned(y) < unsigned(n) &&
                    ((i && !j) || (!i && j)) &&
                    word[index + 1] == board[x][y])
                {
                    if (check_neighbor(board, x, y, m, n, word, index + 1))
                        return true;
                }
            }
        }

        board[r][c] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = int(board.size());
        int n = int(board[0].size());
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (check_neighbor(board, i, j, m, n, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};