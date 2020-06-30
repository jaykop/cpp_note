class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int size = int(nums.size());
        int last = size - 1, offset = 1, swapped = 0;
        for (int i = 0; 0 <= i && i < size; i += offset)
        {
            if ((offset == 1 && nums[i] > target) ||
               (offset == -1 && nums[i] < target)) 
            {
                swap(i, last);
                ++swapped;
                // did not found
                if (swapped == 2) break; 
                offset *= -1;
                i -= offset;
            }
            
            else 
            {
                if (nums[i] == target)
                    return true;
                
                swapped = 0;
            }             
        }
        
        return false;
    }
};
