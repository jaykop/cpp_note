#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//
//class Solution {
//public:
//
//    bool isAnswer(const vector<string>& strs, int len)
//    {
//        for (int i = 1; i < strs.size(); i++)
//        {
//            if (strs[0].substr(0, len) != strs[i].substr(0, len))
//                return false;
//        }
//        return true;
//    }
//
//    string longestCommonPrefix(vector<string>& strs) {
//
//        if (strs.empty()) return "";
//
//        // get min string
//        int size = INT_MAX;
//        string prefix;
//        for (const auto& s : strs)
//            if (s.size() < size)
//            {
//                size = s.size();
//                prefix = s;
//            }
//
//        int low = 1, high = size;
//        while (low <= high)
//        {
//            int mid = (low + high) / 2;
//            if (isAnswer(strs, mid))
//                low = mid + 1;
//            else
//                high = mid - 1;
//
//        }
//
//        return strs[0].substr(0, (high + low) / 2);
//    }
};

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";

        // sort the array by string size
        int size = INT_MAX;
        string prefix;
        for (const auto& s : strs)
            if (s.size() < size)
            {
                size = s.size();
                prefix = s;
            }

        bool pass = false;
        while (pass == false)
        {
            if (prefix.empty()) return prefix;
            pass = true;
            for (int i = 0; i < strs.size(); i++)
            {
                if (strs[i].substr(0, prefix.size()) != prefix)
                {
                    pass = false;
                    prefix = prefix.substr(0, prefix.size() - 1);
                    break;
                }
            }
            if (pass)
                return prefix;
        }

        return "";
    }
};