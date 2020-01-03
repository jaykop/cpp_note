#pragma once
class Solution {
public:

    int hammingDistance(int x, int y) {

        int a = (x ^ y);
        int count = 0;
        while (a) {
            if (a % 2) count++;
            a /= 2;
        }
        return count;
    }
};