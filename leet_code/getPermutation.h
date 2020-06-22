#pragma once
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    string getPermutation(int n, int k) {

        string s;
        int division = 1;
        for (int i = 0; i < n; ++i)
        {
            s += char('1' + i);
            division *= i + 1;
        }

        division /= n; // combinations for each number

        if (k / division > 1)
        {
            char head = char(k / division) + '0';
            s.erase(head - '1', 1);
            s = head + s;

            k = k % division;
        }

        while (k && --k)
        {
            string next;
            int p = -1;
            for (int i = n - 2; i >= 0; --i)
            {
                if (i >= 0 && s[i] < s[i + 1])
                {
                    p = i;
                    break;
                }
            }

            next = s.substr(0, p);

            int smallest = p + 1;
            for (int i = smallest; i < n; ++i)
            {
                if (s[i] > s[p] && s[i] < s[smallest])
                    smallest = i;
            }

            next += s[smallest];
            string tail;
            tail += s.substr(p, smallest - p);
            tail += s.substr(smallest + 1, n - smallest);
            sort(tail.begin(), tail.end());
            s = next + tail;
        }

        return s;
    }
};