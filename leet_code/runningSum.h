class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        size_t size = nums.size();
        for (size_t i = 1 ; i < size; ++i)
            nums[i] += nums[i-1];
        
        return nums;
    }
};