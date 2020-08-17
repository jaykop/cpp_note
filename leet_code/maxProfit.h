class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        if (!prices.empty())
        {
            size_t jSize = prices.size();
            size_t iSize = jSize - 1;
            
            for (size_t i = 0; i < iSize; ++i)
            {
                for (size_t j = i + 1; j < jSize; ++j)
                {
                    int diff = prices[j] - prices[i];
                    if (profit < diff)
                        profit = diff;
                }
            }
        }
        
        return profit;
    }
};