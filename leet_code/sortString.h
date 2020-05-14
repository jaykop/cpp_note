#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string sortString(string s) {

        vector<int> cn(26);
        for (const auto& c : s)
            cn[c - 'a']++;

        int size = int(s.size());
        int i = 0;
        string toReturn;
        bool toggle = false, updated = true, nonZero = true;
        while (nonZero)
        {
            nonZero = false;
            while (0 <= i && i < 26)
            {
                if (cn[i] > 0) {
                    cn[i]--;
                    if (!nonZero) nonZero = cn[i] > 0;
                    toReturn += char(i + 'a');
                }

                if (!toggle) i++;
                else i--;
            }

            if (!toggle) i = 25;
            else i = 0;
            toggle = !toggle;
        }

        return toReturn;
    }
};