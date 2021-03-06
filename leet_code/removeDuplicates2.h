#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) return 0;

        int size = int(nums.size());
        int ans = size;
        int start = -1, end = -1;
        int count = 0;
        int i = 0;
        bool toggle = false;

        while (i < ans - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                ++count;
                if (count > 1)
                {
                    if (start < 0) start = i;
                    if (i == ans - 2)
                        toggle = true;
                }
            }
            if (nums[i] != nums[i + 1] || toggle)
            {
                if (count > 1)
                {
                    int next = start;
                    ans -= (count - 1);
                    for (int n = i + 1; n < size; ++n)
                        nums[++start] = nums[n];
                    i = next;

                }
                toggle = false;
                start = -1;
                count = 0;
            }

            ++i;
        }

        return ans;
    }
};

//???

e : 0 0 1 1 1 2 2 3
i : 0 1 2 3 4 4 5 6
e': 0 0 1 1 2 2 3
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto e : nums) {
            if (i < 2 || e > nums[i - 2])
                nums[i++] = e;
        }
        return i;
    }
};