#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";

        // sort the array by string size
        sort(strs.begin(), strs.end(), []
        (const string& s1, const string& s2)
            {
                return s1.size() < s2.size();
            });

        string prefix = strs[0];
        bool pass = false;
        while (pass == false)
        {
            if (prefix.empty()) return prefix;
            pass = true;
            for (int i = 1; i < strs.size(); i++)
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