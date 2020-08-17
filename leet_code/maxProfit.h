class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0, minPrice = INT_MAX;
        
        if (!prices.empty())
        {
            for (size_t i = 0; i < prices.size(); ++i)
            {
                if (prices[i] < minPrice)
                    minPrice = prices[i];
                else if (profit < prices[i] - minPrice)
                    profit = prices[i] - minPrice;
            }
        }
        
        return profit;
    }
};