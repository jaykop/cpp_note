#pragma once
#include <cmath>
class Solution {
public:
    int maximum69Number(int num) {

        int rest = num,
            digit = 0,
            digit_to_change = -1;

        while (rest != 0)
        {
            int lastrest = rest;
            rest = rest % 10;
            if (rest == 6)
                digit_to_change = digit;
            rest = lastrest - rest;
            rest /= 10;
            digit++;
        }

        if (digit_to_change != -1)
        {
            const int nth_digit = pow(10, digit_to_change);
            num -= 6 * nth_digit;
            num += 9 * nth_digit;
        }

        return num;
    }
};