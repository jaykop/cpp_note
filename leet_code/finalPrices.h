#include <vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int> stack;
        for (int i = 0; i < int(prices.size()); ++i)
        {
            while (stack.size() && prices[stack.back()] >= prices[i])
            {
                prices[stack.back()] -= prices[i];
                stack.pop_back();
            }
            stack.push_back(i);
        }

        return prices;
    }
};

//class Solution {
//public:
//    vector<int> finalPrices(vector<int>& prices) {
//        
//        size_t size = prices.size();
//        for (int i = 0; i < size; ++i )
//        {
//            int j = i + 1;
//            while (j < size && prices[j] > prices[i])
//                ++j;
//            if (j < size)
//                prices[i] -= prices[j];
//        }
//        
//        return prices;
//    }
//};