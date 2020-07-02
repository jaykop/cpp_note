#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int> > subsetsWithDup(vector<int>& S) {
        sort(S.begin(), S.end());
        vector<vector<int>> ret = { {} };
        int size = 0, startIndex = 0;
        for (int i = 0; i < S.size(); i++) {

            startIndex = i > 0 && S[i] == S[i - 1] // check if this is duplicated
                ? size : 0; // if so, add this element to the lists from last step (startIndex = size)
                            // unless add this element to the whole lists
            size = ret.size();
            for (int j = startIndex; j < size; j++) {
                vector<int> temp = ret[j];
                temp.push_back(S[i]);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
