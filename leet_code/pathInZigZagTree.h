#pragma once
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> pathInZigZagTree(int label) {

        // get the lables' row info
        int row = 1;
        int tail = 1, head = tail;
        while (tail < label) {
            head = tail;
            tail += int(pow(2, row));
            row += 1;
        }
        head += 1;

        // setup the result
        vector<int> result;
        result.push_back(label);
        while (label != 1) {

            int index = (label - head)/2;
            int last_tail = head - 1;
            label = last_tail - index;
            result.push_back(label);
            head = (head - 1) / 2 + 1;

        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};