
class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        vector<int> v = triangle.back();
        for (int i = triangle.size() - 2; i >= 0 ; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
                v[j] = triangle[i][j] + min(v[j], v[j+1]);
        }
        return v[0];
    }
};