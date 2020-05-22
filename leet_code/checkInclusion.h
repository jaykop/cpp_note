#pragma once
#include <set>
#include <string>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:

    void recursive(string newStr, string givenStr, 
        set<string>& p, int len)
    {
        int size = givenStr.length();
        for (int i = 0; i < size; i++)
        {
            string given = givenStr;
            string next = newStr + given.substr(i, 1);
            given.erase(i, 1);
            if (next.length() == len)
            {
                p.insert(next);
                return;
            }
            recursive(next, given, p, len);
        }
    }

    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length())
            return false;

        unordered_map<char, int> d1, d2;
        int size1 = s1.length();
        int size2 = s2.length();
        int size = max(size1, size2);
        for (int i = 0; i < size; i++)
        {
            if (i < size1) d1[s1[i]]++;
            if (i < size2) d2[s2[i]]++;
        }
        size = min(size1, size2);
        for (int i = 0; i < size; i++)
        {
            char c = s1[i];
            if (d1[c] > d2[c]) 
                return false;
        }

        set<string> p;
        string start;

        recursive(start, s1, p, size1);

        for (const auto& s : p)
        {
            if (string::npos != s2.find(s))
                return true;
        }

        return false;
    }
};