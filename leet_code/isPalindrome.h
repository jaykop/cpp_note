#pragma once
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {

        //negative numbers not counted
        if (x < 0) return false;
        int max = 1;
        int num_digits = 1;
        while (INT_MAX / 10 > max && x >= max * 10)
        {
            num_digits++;
            max *= 10;
        }
        num_digits /= 2;

        int x1 = x, x2 = x;
        while (num_digits)
        {
            int rest = x1 % max;
            int front_digit = (x1 - rest) / max;
            int back_digit = x2 % 10;

            if (front_digit != back_digit)
                return false;

            x1 = rest;
            x2 = (x2 - back_digit) / 10;
            max /= 10;
            num_digits--;

        }

        return true;
    }
};