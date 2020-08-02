class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans(2 * n, 0);
        
        for (int i = 0 ; i < 2*n ; ++i)
        {
            if (i < n)
                ans[i * 2] = nums[i];
            else
                ans[(i - n) * 2 + 1] = nums[i];
        }
        
        return ans;
    }
};