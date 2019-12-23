#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

        string toReturn;
        int left_counter = 0, right_counter = 0;
        // 
        for (auto it = s.begin();
            it != s.end();  it++) {

            if (*it == '(') {
                left_counter++;

                // add to the return
                if (left_counter != 1)
                    toReturn += *it;

            }

            else if (*it == ')') {
                right_counter++;
            
                // both counters are non-zero,
                // and the same,
                if (left_counter && right_counter
                   && left_counter == right_counter) {

                    // init counters
                    right_counter = left_counter = 0;
                }

                else
                    toReturn += *it;

            }              

        }

        return toReturn;
    }
};