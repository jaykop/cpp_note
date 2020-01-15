#pragma once
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    map<string, string> dict;

    string convert(const string& s) {
        return string(1, char(atoi(s.c_str()) + 96));
    }

    string freqAlphabets(string s) {

        string toReturn;
        bool add = false;
        int last = int(s.size()) - 1;

        for (int i = last; i >= 0; i--) {

            if (s[i] == '#') {
                add = true;
                continue;
            }

            if (add) {
                toReturn.insert(0, convert(s.substr(i - 1, 2)));
                add = false;
                i--;
            }

            else 
                toReturn.insert(0, convert(string(1, s[i])));
        }

        return toReturn;
    }
};