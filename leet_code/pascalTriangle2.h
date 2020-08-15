class Solution {
public:
    
    vector<vector<int>> res;
    
    void spread()
    {
        res.emplace_back(1, 1);
        const auto& last = res[res.size() - 2];
        for (int i = 1; i < int(last.size()); ++i)
            res.back().emplace_back(last[i - 1] + last[i]);

        res.back().emplace_back(1);
    }
    
    vector<int> getRow(int rowIndex) {
        
        int numRows = rowIndex + 1;
        
        if (numRows)
        {
            if (numRows > 0)
                res.emplace_back(1, 1);
            if (numRows > 1)
                res.emplace_back(2, 1);
            if (numRows > 2)
            {
                numRows -= 2;
                while (numRows--)
                    spread();
            }
        }

        return res[rowIndex];
    }
    
};