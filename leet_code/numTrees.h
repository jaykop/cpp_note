#pragma once
class Solution {
public:
    int numTrees(int n) {

        if (n < 2) return n;
        int count = 2, ans = 2;

        while (--n > 1)
        {
            ++count;
            int bits = count;
            ans *= count;
            while (bits & 1)
                bits >>= 1;
            if (!bits) --ans;

        }

        return ans;
    }
};

// Catalan number

class Solution {
public:

    int numTrees(int n) {

        int dp[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};