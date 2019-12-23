#pragma once
#include <vector>
#include <string>

using namespace std;

// uppercase 65 ~ 90 
// lowercase 97 ~ 122
static const vector<string> dict = { ".-","-...","-.-.","-..",".","..-.","--.",
       "....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
       "...","-","..-","...-",".--","-..-","-.--","--.." };

class Solution {
public:

    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> new_words;

        // iterate thru the vector
        for (const auto& s : words) {

            string converted_word ;
            
            // iterate thru the word
            for (const auto& c : s) {
                int index = ::tolower(c) - 97;
                converted_word += dict[index];
            }

            bool found = false;
            for (const auto& ns : new_words) {

                if (ns == converted_word) {
                
                    found = true;
                    break;
                }
            }

            if (!found)
                new_words.push_back(converted_word);
        }

        return int(new_words.size());
    }
};