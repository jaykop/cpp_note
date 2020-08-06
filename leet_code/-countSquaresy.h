class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int res = 0;
        for (unsigned i = 0; i < matrix.size(); ++i)
        {
            for (unsigned j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] && i && j)
                    matrix[i][j] += min({matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]});
                res += matrix[i][j];
            }
        }
        
        return res;
    }
};