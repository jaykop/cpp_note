#pragma once
// best so far
class Solution {
public:

    unsigned factorial(unsigned n, unsigned limit)
    {
        if (n == 0 || n == 1) return 1;
        else if (limit == 1) return n;
        return n * factorial(n - 1, --limit);
    }

    int uniquePaths(int m, int n) {

        if (m == 1 || n == 1) return 1;

        --m; --n;
        unsigned output = 0;

        if (m > n)
            output = factorial(m + n, n) / factorial(n, n);
        
        else 
            output = factorial(m + n, m) / factorial(m, m);
        
        return output;
    }
};