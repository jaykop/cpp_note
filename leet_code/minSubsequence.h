class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        if (nums.size() == 1)
            return nums;
        
        int sum = 0;
        for (auto i : nums)
            sum += i;
        
        sort(nums.begin(), nums.end());
        
        int sum_rest = sum;
        int sum_res = 0;
        
        vector<int> res;
        
        for (auto rit = nums.rbegin(); 
             rit != nums.rend(); rit++)
        {
            sum_res += *rit; 
            sum_rest -= *rit; 
            res.emplace_back(*rit);
            
            if (sum_res > sum_rest)
                break;
        }
        
        return res;
    }
};