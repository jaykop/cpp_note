#pragma once
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {

        unordered_map<string, int> table;

        for (const auto& s : cpdomains)
        {
            int space = s.find_first_of(" ");
            int occurence = stoi(s.substr(0, space));
            int last = s.length() - 1;
            string str = s.substr(space + 1, last);
            vector<int> dots;
            dots.emplace_back(-1);
            auto found = str.find(".");
            do {
                dots.emplace_back(found);
                found = str.find(".", found + 1);

            } while (found != string::npos);
            while (!dots.empty())
            {
                string subs = str.substr(dots.back() + 1, last);
                table[subs] += occurence;
                dots.pop_back();
            }
            //table[s] += occurence;
        }

        vector<string> res;
        for (const auto& s : table)
        {
            res.emplace_back(to_string(s.second) + " " + s.first);
        }

        return res;
    }
};