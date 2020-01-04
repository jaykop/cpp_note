class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        int size = int(nums.size());
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)
            if (!(i % 2)) sum += nums[i];
        return sum;
    }
};