#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {

        string toReturn;
        for (auto it = address.begin();
            it != address.end(); it++) {

            if (*it == '.') {
                toReturn += "[";
                toReturn += ".";
                toReturn += "]";
            }
            else
                toReturn += *it;
        }

        return toReturn;
    }
};