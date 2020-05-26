#pragma once
#include <string>
using namespace std;

class Solution {
public:

    void remove(string& s, int& res,
        char toFind, char prefix, int usual, int unusual)
    {
        auto found = s.find(toFind);
        while (found != string::npos)
        {
            if (found && s[found - 1] == prefix)
            {
                s = s.erase(found - 1, 2);
                res += unusual;
            }
            else
            {
                s = s.erase(found, 1);
                res += usual;
            }
            found = s.find(toFind);
        }
    }

    int romanToInt(string s) {

        // first things first
        int res = 0;
        remove(s, res, 'M', 'C', 1000, 900);
        remove(s, res, 'D', 'C', 500, 400);
        remove(s, res, 'C', 'X', 100, 90);
        remove(s, res, 'L', 'X', 50, 40);
        remove(s, res, 'X', 'I', 10, 9);
        remove(s, res, 'V', 'I', 5, 4);

        auto found = s.find('I');
        while (found != string::npos)
        {
            s = s.erase(found, 1);
            res += 1;
            found = s.find('I');
        }

        return res;
    }
};