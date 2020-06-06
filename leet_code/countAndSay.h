#pragma once
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    unordered_map<int, string> table;
    int last_n = 3;
    string countAndSay(int n) {

        if (table.empty())
        {
            table[1] = "1";
            table[2] = "11";
            table[3] = "21";
        }

        if (table.find(n) == table.end())
        {
            while (last_n != n)
            {
                string get = table[last_n];
                table[last_n + 1] = "";
                int size = int(get.length());
                char offset = '0';
                int last_c = get[0] - offset;
                int count = 0;
                for (int i = 0; i < size; i++)
                {
                    int c = get[i] - offset;
                    if (c != last_c)
                    {
                        table[last_n + 1].append(to_string(count) + to_string(last_c));
                        count = 1;
                    }
                    else
                        count++;
                    last_c = c;
                }
                table[last_n + 1].append(to_string(count) + to_string(last_c));

                last_n++;
            }
        }

        return table[n];
    }
};