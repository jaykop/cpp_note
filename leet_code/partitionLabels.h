#pragma once
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// *Could not solve*

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>res;

        // log every last position of each char
        vector<int> last(26, 0);
        for (int i = 0; i < S.size(); ++i) {
            last[S[i] - 'a'] = i;

        }
        int begin = 0;
        int end = 0;
        for (int i = 0; i < S.size(); ++i) {
            end = max(end, last[S[i] - 'a']);
            if (end == i) {
                res.push_back(i - begin + 1);
                begin = i + 1;

            }
        }
        return res;
    }
};