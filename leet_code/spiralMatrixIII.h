#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// low memory...
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {

        vector<vector<int>> res;
        int m1 = 1, m2 = 1;
        int total = R* C, count = 0, added =0;
        total *= total;
        int direction = 0; // 0 - right, 1 - down, 2 - left, 3 - up

        while (added < total)
        {
            if (0 <= r0 && r0 < R &&
                0 <= c0 && c0 < C) {
                // add current pos
                added++;
                vector<int> pos = { r0, c0 };
                res.push_back(pos);
            }

            // movements
            switch (direction)
            {
            case 0: // right
                c0++;
                break;
            case 1: // down
                r0++;
                break;
            case 2: // left
                c0--;
                break;
            case 3: // up
                r0--;
                break;
            }

            count++;
            // switch direction
            if (count == m1 * m2)
            {
                direction = ++direction % 4;
                if (m1 == m2)
                    m1++;
                else
                    m2++;
            }
        }

        return res;
    }
};