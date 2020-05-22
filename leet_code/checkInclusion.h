#pragma once
#include <set>
#include <string>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length())
            return false;

        int size1 = s1.length();
        int size2 = s2.length();
        int size = max(size1, size2);

        unordered_map<char, int> d1, d2;
        for (int i = 0; i < size; i++)
        {
            if (i < size1) d1[s1[i]]++;
            if (i < size2) d2[s2[i]]++;
        }

        size = min(size1, size2);
        for (int i = 0; i < size; i++)
        {
            char c = s1[i];
            // more c in s1
            if (d1[c] > d2[c])
                return false;
        }

        int count = 0;
        for (int i = 0; i < size2; i++)
        {
            // check if c is in s1
            if (s1.find(s2[i]) != string::npos)
            {
                if (d1[s2[i]] > 0)
                    d1[s2[i]]--;
                else
                    return false;

                // check continuity
                count++;
            }
            else
            {
                // broken or done
                if (count)
                    break;
            }
        }

        // s1 can be in count range
        if (count < size1)
            return false;

        return true;
    }
};