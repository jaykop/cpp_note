#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {

        string res;
        res.resize(indices.size());
        auto c = s.begin();
        for (auto i : indices)
            res[i] = *(c++);

        return res;
    }
};