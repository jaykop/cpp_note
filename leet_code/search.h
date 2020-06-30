#pragma once
#include <vector>
using namespace std;

// seems better using dc
class Solution {
public:

    void dc(vector<int>& nums, int left, int right,
        int target, bool& found)
    {
        int mid = (right + left) / 2;
        if (found
            || (left == right && nums[left] == target)
            || nums[mid] == target)
        {
            found = true;
            return;
        }

        int i = left, j = right;

        while (i <= j)
        {
            while (i < mid) ++i;
            while (mid < j) --j;

            if (i <= j)
            {
                ++i;
                --j;
            }
        }

        if (left <= j)  dc(nums, left, j, target, found);
        if (i <= right) dc(nums, i, right, target, found);
    }

    bool search(vector<int>& nums, int target) {

        bool ans = false;
        if (!nums.empty())
            dc(nums, 0, int(nums.size()) - 1, target, ans);

        return ans;
    }
};


// decent solution
//class Solution {
//public:
//    bool search(vector<int>& nums, int target) {
//        
//        int size = int(nums.size());
//        int last = size - 1, offset = 1, swapped = 0;
//        for (int i = 0; 0 <= i && i < size; i += offset)
//        {
//            if ((offset == 1 && nums[i] > target) ||
//               (offset == -1 && nums[i] < target)) 
//            {
//                swap(i, last);
//                ++swapped;
//                // did not found
//                if (swapped == 2) break; 
//                offset *= -1;
//                i -= offset;
//            }
//            
//            else 
//            {
//                if (nums[i] == target)
//                    return true;
//                
//                swapped = 0;
//            }             
//        }
//        
//        return false;
//    }
//};
