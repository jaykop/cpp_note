#pragma once
class Solution {
public:
    int findNumbers(vector<int>& nums) {

        // value to be returned
        int even_digits = 0;

        // iterate the vector
        for (auto i : nums) {
            
            int digit_counter = 0;
            // count the num of digits
            do { 

                // remove the last digit
                i -= (i % 10); 
                i /= 10;

                digit_counter++;
            
            } while (i);

            // 
            if (!(digit_counter % 2))
                even_digits++;
        }

        return even_digits;
    }
};