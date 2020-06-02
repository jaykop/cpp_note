class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if (target <= nums[0])
            return 0;
        else if (target > nums.back())
            return nums.size();
        
        for (int i =0; i < nums.size() - 1; i ++)
        {
            if (nums[i] < target && target <= nums[i+1])
                return i + 1;
        }
        
        return 0;
    }
};