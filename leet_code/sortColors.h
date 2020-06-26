class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int two = 0, one = 0, zero = 0;
        int size = int(nums.size());
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == 0) ++zero;
            else if (nums[i] == 1) ++one;
            else if (nums[i] == 2) ++two;
        }
        
        for (int i = 0; i < size; ++i)
        {
            if (zero){ --zero; nums[i] = 0; }
            else if (one){ --one; nums[i] = 1; }
            else if (two){ --two; nums[i] = 2; }
        }
    }
};