class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> toReturn;
        int largest = 0;
        for (const auto& i : candies)
        {
            if (largest < i)
                largest = i;
        }
        
        for (const auto& i : candies)
        {
            if (largest <= i + extraCandies)
                toReturn.emplace_back(true);
            else
                toReturn.emplace_back(false);
        }
        
        return toReturn;
    }
};