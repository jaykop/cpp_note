#pragma once
#include <vector>
using namespace std;

//class Solution {
//public:
//
//    vector<int> next(vector<int>& nums, vector<bool>& bits)
//    {
//        vector<int> res;
//        int size = int(bits.size());
//        for (int i = 0; i < size; ++i)
//            if (bits[i]) res.emplace_back(nums[i]);
//
//        // next binary number
//        for (int i = size - 1; i >= 0; --i)
//        {
//            bits[i] = !bits[i];
//            if (bits[i]) break;
//        }
//
//        return res;
//    }
//
//    vector<vector<int>> subsets(vector<int>& nums) {
//
//        vector<vector<int>> ans;
//        vector<bool> bits(nums.size(), false);
//        int size = 1;
//        size <<= nums.size();
//
//        while (size--)
//            ans.emplace_back(next(nums, bits));
//
//        return ans;
//    }
//};

// other(better) bitwise solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) { // for every number from 1 to 2^n
            for (int j = 0; j < n; j++) { // for each bit digit
                if ((i >> j) & 1) { // the position of '1'
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};

//// iterative solution
//class Solution {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<vector<int>> subs = { {} };
//        for (int num : nums) { // for each number
//            int n = subs.size();
//            for (int i = 0; i < n; i++) {
//                subs.push_back(subs[i]); // add an existing subset
//                subs.back().push_back(num); // 
//            }
//        }
//        return subs;
//    }
//};