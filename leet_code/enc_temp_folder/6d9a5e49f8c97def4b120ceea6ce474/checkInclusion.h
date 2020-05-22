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

        for (const auto& c : d1)
        {
            // more c in s1 which is not possible case
            if (c.second > d2[c.first])
                return false;
        }

        auto temp_d = d1;
        int count = 0;
        int lastStart = 0;
        for (int i = 0; i < size2; i++)
        {
            if (temp_d.find(s2[i]) == temp_d.end()
                || temp_d[s2[i]] == 0)
            {
                if (count)
                {
                    if (count == size1)
                        return true;

                    if (temp_d[s2[i]] == 0)
                    {
                        if (lastStart == size2)
                            return false;

                        temp_d[s2[lastStart++]]++;
                        count--;
                        i--;
                    }
                }
            }
            else
            {
                if (!count)
                    lastStart = i;
                temp_d[s2[i]]--;
                count++;
            }
        }

        if (count == size1)
            return true;

        return false;
    }
};