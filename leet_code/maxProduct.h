class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int m1 = nums[0], m2 = nums[1];
        if (nums.size() > 2)
        {
            for (int i = 2; i < int(nums.size()); ++i)
            {
                int max = std::max(std::max(m1, m2), nums[i]);
                int mid = std::max(std::min(m1, m2), std::min(std::max(m1, m2), nums[i]));
                m1 = max;
                m2 = mid;
            }
        }
        return (m1 - 1) * (m2 - 1);
    }
};