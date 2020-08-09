#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// this is best I could do
class Solution {
public:

    bool isAnagram(const string& a, string b)
    {
        if (a.length() != b.length())
            return false;

        for (auto c : a)
        {
            auto found = b.find(c);
            if (found == string::npos)
                return false;
        }

        sort(b.begin(), b.end());
        if (a != b)
            return false;

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;

        string a = "bdsdf";

        while (!strs.empty())
        {
            auto it1 = strs.begin();
            vector<string> strings;
            strings.emplace_back(*it1);
            string str1 = (*it1);
            sort(str1.begin(), str1.end());
            for (auto it2 = strs.begin() + 1; it2 != strs.end(); )
            {

                if (isAnagram(str1, (*it2)))
                {
                    strings.emplace_back(*it2);
                    it2 = strs.erase(it2);
                }
                else
                    ++it2;
            }

            res.emplace_back(strings);
            it1 = strs.erase(it1);
            
        }

        return res;
    }
};