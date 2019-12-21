#pragma once
class Solution {
public:
    string toLowerCase(string str) {
        // uppercase 65 ~ 90 
        // lowercase 97 ~ 122
        for (auto& c : str)
            if (65 <= c && c <= 90)
                c += 32;
        return str;
    }
};