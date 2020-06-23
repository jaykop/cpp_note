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

// with dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
};