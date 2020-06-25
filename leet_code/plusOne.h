class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int size = int(digits.size());
        ++digits[size - 1];
        for (int i = size - 1; i > 0; --i)
        {
            if (digits[i] == 10)
            {
                digits[i] = 0;
                ++digits[i - 1];
            }
        }
        
        if (digits[0] == 10)
        {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};