#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        vector<string> muls;
        char zero = '0';
        int n1 = 0, n2 = 0;
        string addup, result;
        for (int i = num2.size() - 1; i >= 0; --i)
        {
            n1 = int(char(num2[i]) - zero);

            addup.clear();
            result.clear();
            int count = num2.size() - 1 - i;
            while (count--)
                result += '0';

            for (int j = num1.size() - 1; j >= 0; --j)
            {
                n2 = int(char(num1[j]) - zero);
                int mul = n1* n2;
                int add = 0;
                if (!addup.empty())
                    add = int(addup[0] - zero);
                addup.clear();
                int rest = (mul + add) % 10;

                result.insert(0, 1, char(rest + zero));
                if (mul + add >= 10)
                    addup += char((mul + add)/10) + zero;
            }
            addup += result;
            muls.emplace_back(addup);
        }

        if (muls.size() == 1)
            return muls[0];

        addup.clear();
        result.clear();
        string res = muls[0];

        for (int i = 1; i< muls.size(); i++ )
        {
            int size = 0;
            string remnant;
            if (muls[i].size() < res.size())
            {
                size = muls[i].size();
                remnant = res.substr(0, res.size() - size);
                res = res.substr(res.size() - size, size);
            }
            else
            {
                size = res.size();
                remnant = muls[i].substr(0, muls[i].size() - size);
                muls[i] = muls[i].substr(muls[i].size() - size, size);
            }

            for (int j = size - 1; j >= 0; --j)
            {
                n1 = int(char(res[j]) - zero);
                n2 = int(char(muls[i][j]) - zero);
                int add = 0;
                if (!addup.empty())
                    add = int(addup[0] - zero);
                addup.clear();
                int sum = n1 + n2 + add;
                if (sum > 9)
                    addup += "1";

                int rest = sum % 10;
                result.insert(0, 1, char(rest + zero));
            }

            res = remnant;
            remnant.clear();
            size = res.size();

            for (int j = size - 1; j >= 0; --j)
            {
                n1 = int(char(res[j]) - zero);
                int add = 0;
                if (!addup.empty())
                    add = int(addup[0] - zero);
                addup.clear();
                int sum = n1 + add;
                if (sum > 9)
                    addup += "1";

                int rest = sum % 10;
                remnant.insert(0, 1, char(rest + zero));
            }
            res = addup + remnant + result;
            result.clear();
            addup.clear();
        }

        return res;
    }
};