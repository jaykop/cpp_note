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
            for (auto it  = a.begin() ; it != a.end(); it++)
            {
                if (*it == q) {
                    int v = *it;
                    toReturn.emplace_back(distance(a.begin(), it));
                    a.erase(it);
                    a.push_front(v);
                    break;
                }
            }
        }

        return toReturn;
    }
};