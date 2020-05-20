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

//class Solution {
//public:
//    string reverseWords(string s) {
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] != ' ') {   // when i is a non-space
//                int j = i;
//                for (; j < s.length() && s[j] != ' '; j++) {} // move j to the next space
//                reverse(s.begin() + i, s.begin() + j);
//                i = j - 1;
//            }
//        }
//
//        return s;
//    }
//};