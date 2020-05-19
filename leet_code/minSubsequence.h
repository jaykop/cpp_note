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

// class Solution {
// public:
    // vector<int> minSubsequence(vector<int>& nums) {
        
        // int sub_sum = 0;
        // int half_sum = accumulate(begin(nums), end(nums), 0) / 2;
        // vector<int> res;
        // priority_queue<int> pq(begin(nums), end(nums));
        // while (half_sum >= sub_sum)
        // {            
            // int back = pq.top();
            // sub_sum += back;
            // res.emplace_back(back);
            // pq.pop();
            
        // }
        // return res;
    // }
// };