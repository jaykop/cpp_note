#pragma once
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (haystack == needle || needle.empty())
            return 0;
        else if (haystack.empty() || haystack.size() < needle.size())
            return -1;

        for (unsigned i = 0; i < haystack.size(); )
        {
            if (haystack[i] == needle[0])
            {
                bool match = true;
                int res = i++;
                for (unsigned j = 1; i < haystack.size() && j < needle.size(); i++, j++)
                {
                    if (haystack[i] != needle[j])
                    {
                        i = res + 1;
                        break;
                    }
                }

                if (needle.size() == i - res)
                    return res;
            }
            else i++;
        }

        //auto found = haystack.find(needle);
        //if (found != string::npos) 
        //    return found;

        return -1;
    }
};