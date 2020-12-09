class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int max = 0, m = nums[0];
        map<int, int> table;
        
        for (int& i : nums)
        {
            table[i]++;
            if (max < table[i])
            {
                max = table[i];
                m = i;
            }
        }
        
        return m;
    }
};