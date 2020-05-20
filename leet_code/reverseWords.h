#pragma once
class Solution {
public:
    string reverseWords(string s) {

        vector<string> chunks;
        string mid, res;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ') {
                chunks.emplace_back(mid);
                mid = "";
            }
            else
                mid += s[i];
        }
        chunks.emplace_back(mid);

        while (!chunks.empty())
        {
            auto str = chunks.back();
            chunks.pop_back();
            res += str;
            if (!chunks.empty())
                res += " ";
        }

        return res;
    }
};