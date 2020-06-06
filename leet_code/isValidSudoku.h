#pragma once
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        char zero = '0';
        unordered_map<int, int> table1, table2;

        vector<int> smallrects = { 1, 4, 7 },
            range = { -1, 0, 1 };

        for (auto i1 : smallrects)
        {
            for (auto j1 : smallrects)
            {
                table1.clear();
                for (auto i2 : range)
                {
                    for (auto j2 : range)
                    {
                        int x = i1 + i2;
                        int y = j1 + j2;
                        if (board[x][y] != '.')
                        {
                            int num = int(board[x][y] - zero);
                            if (table1[num] > 0)
                                return false;
                            table1[num]++;
                        }
                    }
                }
            }
        }

        table1.clear();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = int(board[i][j] - zero);
                    if (table1[num] > 0)
                        return false;
                    table1[num]++;
                }

                if (board[j][i] != '.')
                {
                    int num = int(board[j][i] - zero);
                    if (table2[num] > 0)
                        return false;
                    table2[num]++;
                }
            }
            table1.clear();
            table2.clear();
        }

        return true;
    }
};