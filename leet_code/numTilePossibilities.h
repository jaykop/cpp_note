#pragma once
#include <set>
#include <string>
using namespace std;

class Solution {
public:

    set<string> table;
    int len;

    void dfs(string str, string left) {

        if (!str.empty())
            table.insert(str);

        for (auto it = left.begin(); it != left.end(); it++) {
            auto str_copy = str;
            auto left_copy = left;
            str_copy += *it;
            left.erase(it);
            if (int(str_copy.length()) <= len)
                dfs(str_copy, left);
            left = left_copy;
        }
    }

    int numTilePossibilities(string tiles) {

        len = int(tiles.length());
        dfs("", tiles);

        return int(table.size());
    }
};