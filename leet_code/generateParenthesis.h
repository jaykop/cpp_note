#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void recursive(vector<string>& v, string s, int n, int wrapup)
    {
        if (n == 0)
        {
            for (int i = 0; i < wrapup; i++)
                s += ')';

            v.push_back(s);
            return;
        }

        if (s.empty() || s.back() == ')')
        {
            if (wrapup > 0)
            {
                string s1 = s;
                for (int i = 0; i < wrapup; i++)
                {
                    s1 += ')';
                    recursive(v, s1 + '(', n - 1, wrapup - i);
                }
            }
            recursive(v, s + '(', n - 1, wrapup + 1);
        }
        else
        {
            string s1 = s, s2 = s;
            s1 += '(';
            recursive(v, s1, n - 1, wrapup + 1);
            s2 += ')';
            recursive(v, s2, n, wrapup - 1);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> res;

        string s;
        recursive(res, s, n, 0);

        return res;
    }
};