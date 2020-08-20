class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty() || prices.size() == 1)
            return 0;
        
        size_t size = prices.size();
        int m;
        for (size_t i = 1; i < size; ++i)
        {
            int diff = prices[i] -  prices[i - 1];
            if (diff > 0) m += diff;
        }
        
        return m;
    }
};