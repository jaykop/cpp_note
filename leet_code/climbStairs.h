class Solution {
public:
    
    vector<int> cnt;
    
    int memo(int n)
    {
        if (cnt[n] == -1)
            cnt[n] = memo(n - 1) + memo(n -2);
        
        return cnt[n];
    }
    
    int climbStairs(int n) {
        
        cnt.resize(3, -1);
        
        cnt[0] = 0;
        cnt[1] = 1;
        cnt[2] = 2;
        
        if (n > 2) cnt.resize(n + 1, -1);
        
        return memo(n);
    }
};