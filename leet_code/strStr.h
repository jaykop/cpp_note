#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    void computeLPSArray(const string& s, vector<int>& v)
    {
        // length of the previous longest prefix suffix 
        int len = 0;

        v.resize(s.size(), 0);

        // the loop calculates lps[i] for i = 1 to M-1 
        int i = 1;
        while (i < s.size()) {
            if (s[i] == s[len]) {
                len++;
                v[i] = len;
                i++;
            }
            else // (pat[i] != pat[len]) 
            {
                // This is tricky. Consider the example. 
                // AAACAAAA and i = 7. The idea is similar 
                // to search step. 
                if (len != 0) {
                    len = v[len - 1];

                    // Also, note that we do not increment 
                    // i here 
                }
                else // if (len == 0) 
                {
                    v[i] = 0;
                    i++;
                }
            }
        }
    }

    void searchLPS(const string& s, vector<int>& v)
    {
        int size = s.size();
        v.resize(size, 0);

        for (int last = 1; last < size - 1; last++)
        {
            int i = 0, j = last;
            while (i < last && s[i] == s[j])
            {
                i++;
                j--;
            }

            v[last] = i;
        }
    }

    int strStr(string haystack, string needle) {

        string s("AABAACAABAA");
        vector<int> v;
        searchLPS(s, v);
        computeLPSArray(s, v);
        if (haystack == needle || needle.empty())
            return 0;

        else if (haystack.empty() || 
            haystack.size() < needle.size())
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

