#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;
class Solution {
public:

    int word_score(const string& s,
        const vector<int>& score) {

    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        int result = 0;
        map<char, int> dict;
        vector<int> score_board;

        //
        for (const auto& c : letters)
            dict[c]++;

        // cut out the words cannot compose
        for (const auto& w : words) {

            int sum = 0;
            bool found = true;

            for (const auto& c : w) {
                if (!dict[c]) {
                    found = false;
                    break;
                }
                sum += score[c - 97];
            }

            if (!found)
                sum = -1;
            
            score_board.push_back(sum);
        }

        // 

        return result;
    }
};