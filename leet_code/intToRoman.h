#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    void arrange(int& num, int toCheck, string toAdd, string& s)
    {
        while (num >= toCheck)
        {
            num -= toCheck;
            s.append(toAdd);
        }
    }

    string intToRoman(int num) {

        string s;

        if (num > 3)
        {
            arrange(num, 1000, "M", s);
            arrange(num, 900, "CM", s);
            arrange(num, 500, "D", s);
            arrange(num, 400, "CD", s);
            arrange(num, 100, "C", s);
            arrange(num, 90, "XC", s);
            arrange(num, 50, "L", s);
            arrange(num, 40, "XL", s);
            arrange(num, 10, "X", s);
            arrange(num, 9, "IX", s);
            arrange(num, 5, "V", s);
            arrange(num, 4, "IV", s);
        }

        for (int i = 0; i < num; i++)
            s.append("I");

        return s;
    }
};