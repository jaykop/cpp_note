#pragma once
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    void read(queue<int>& cnt,
        vector<vector<int>>& matrix,
        int r, int c, int size,
        bool update_row, bool increase)
    {
        if (!cnt.empty())
        {
            int count = size;
            int i = r, j = c;
            while (count)
            {
                count--;
                cnt.push(matrix[i][j]);
                if (update_row)
                {
                    if (increase)
                        i++;
                    else i--;
                }
                else
                {
                    if (increase)
                        j++;
                    else j--;
                }
            }

        }

        else
        {
            while (size)
            {
                cnt.push(matrix[r][c]);
                if (update_row)
                {
                    if (increase)
                        r++;
                    else r--;
                }
                else
                {
                    if (increase)
                        c++;
                    else c--;
                }
                size--;
            }
        }
    }

    void write(queue<int>& cnt,
        vector<vector<int>>& matrix,
        int r, int c, int size,
        bool update_row, bool increase)
    {
        if (!cnt.empty())
        {
            int count = size;
            int i = r, j = c;
            while (count)
            {
                count = size;
                i = r, j = c;
                while (count)
                {
                    int n = cnt.front();
                    cnt.pop();
                    count--;
                    matrix[i][j] = n;
                    if (update_row)
                    {
                        if (increase)
                            i++;
                        else i--;
                    }
                    else
                    {
                        if (increase)
                            j++;
                        else j--;
                    }
                }
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {

        // the size is n x n;
        int n = int(matrix.size());
        queue<int> cnt;

        int last = n;
        int size = n;

        for (int i = 0; 0 < size; )
        {
            read(cnt, matrix, i, i, size, false, true);
            read(cnt, matrix, i, last - 1, size, true, true);
            read(cnt, matrix, last - 1, last - 1, size, false, false);
            read(cnt, matrix, last - 1, i, size, true, false);

            write(cnt, matrix, i, last - 1, size, true, true);
            write(cnt, matrix, last - 1, last - 1, size, false, false);
            write(cnt, matrix, last - 1, i, size, true, false);
            write(cnt, matrix, i, i, size, false, true);

            ++i;
            last = n - i;
            size = n - i * 2;
        }
    }
};