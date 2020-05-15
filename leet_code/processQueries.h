#pragma once
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {

        list<int> a;
        vector<int > toReturn;
        for (int i = 1; i <= m; i++)
            a.emplace_back(i);

        for (auto& q : queries)
        {
            int i = 0;
            for (auto it = a.begin(); it != a.end(); it++)
            {
                if (*it == q) {
                    toReturn.emplace_back(i);
                    a.erase(it);
                    a.push_front(q);
                    break;
                }
                i++;
            }
        }

        return toReturn;
    }
};

// do not use std::distance!!!!