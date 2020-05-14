#pragma once
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std; 
class Solution {
public:
    int minSteps(string s, string t) {

        // vector is faster than hash map!
        /*int size = int(s.length());
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        for (int i = 0; i < size; i++)
        {
            cnt1[s[i] - 'a']++;
            cnt2[t[i] - 'a']++;
        }

        int toReturn = 0;
        for (int i = 0; i < 26; i++)
        {
            int sub = cnt1[i] - cnt2[i];
            if (sub > 0)
                toReturn += sub;
        }

        return toReturn;*/

        int size = int(s.length());
        unordered_map <int, int> record_s, record_t;
        for (int i = 0; i < size; i++)
        {
            record_s[s[i] - 'a']++;
            record_t[t[i] - 'a']++;
        }

        int toReturn = 0;
        for (const auto& c : record_t)
        {
            int sub = c.second - record_s[c.first];
            if (sub > 0)
                toReturn += sub;
        }

        return toReturn;
    }
};