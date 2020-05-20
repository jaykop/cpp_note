class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> res;
        int back = target.back();
        for (int i = 1, j = 0; i <= back && i <= n; i++)
        {
            res.push_back("Push");
            if (i != target[j])
                res.push_back("Pop");
            else j++;
        }
        
        return res;
    }
};