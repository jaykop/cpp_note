#pragma once
#include <cmath>

using namespace std;

// best answer that Ive done
class Solution {
public:
    double myPow(double x, int n) {

        if (x)
        {
            double res = 1.0;

            if (n != 0 && x != 1 && x != -1)
            {
                const bool neg = n < 0;
                unsigned new_n = abs(n);
                unsigned count = 1;
                res = x;

                while (count * 2 < new_n)
                {
                    res *= res;
                    count <<= 1;
                }

                while (count < new_n)
                {
                    res *= x;
                    count++;
                }

                if (neg)
                    res = 1 / res;
            }

            if (n % 2 && x == -1)
                res *= -1;

            return res;
        }

        return 0.0;
    }
};

// best answer I found
class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == -1) {
            if (n % 2 == 0) return 1;
            else return -1;
        }
        
        // how do I know this shit??
        if (n == INT_MIN) return 0;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double ret = 1.0;
        while (n > 0) {
            if ((n & 1) != 0)
                ret *= x;
            x = x * x;
            n = n >> 1;
        }
        return ret;

    }
};