class Solution {
public:
    
    vector<int> res;
    
    void spread()
    {
        const auto last = res;
        res.clear();
        res.emplace_back(1);
        for (int i = 1; i < int(last.size()); ++i)
            res.emplace_back(last[i - 1] + last[i]);
        res.emplace_back(1);
    }
    
    vector<int> getRow(int rowIndex) {
        
        if (rowIndex == 0)
            res = {1};
        else 
        {
            res = {1, 1};
            if (rowIndex > 1)
            {
                while (--rowIndex)
                    spread();
            }
        }
        
        return res;
    }
    
};