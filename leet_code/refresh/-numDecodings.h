#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    int numDecodings(string s) {
        int prev = 1, // save for valid case
			pp = 0, n = s.size();
        for(int i=n-1;i>=0;i--) {
			// if s[i] is zero, set current 0
			// unless succeed the prev 
            int current = s[i]=='0' ? 0 : prev;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) current+=pp; // figured out the string is valid
            pp = prev;
            prev = current;
        }
        return s.empty()? 0 : p;   
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n + 1, -1);
        mem[n] = 1;
        return s.empty() ? 0 : num(0, s, mem);
    }

    int num(int i, string& s, vector<int>& mem) {
        if (mem[i] > -1) 
            return mem[i];

        // invalid case by zero
        if (s[i] == '0') 
            return mem[i] = 0;

        int res = num(i + 1, s, mem); // single digit case

        // two digits case
        if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) 
            res += num(i + 2, s, mem);
        return mem[i] = res;
    }

    /*int count = 0;

    int numDecodings(string s) {

        int count = 0;

        int size = int(s.length());
        if (!s.empty() && s[0] == '0') return 0;
        else if (s.size() >= 1) count = 1;
        
        if (size > 1)
        {
            for (int i = 1; i < size; ++i)
            {
                if (s[i] == '0')
                {
                    if (s[i - 1] != '1' && s[i - 1] != '2')
                        return 0;

                    else
                    {
                        if (count > 1) --count;
                    }
                }

                else if (s[i] != '0' &&
                    (s[i - 1] == '1' && s[i] <= '9') ||
                    (s[i - 1] == '2' && s[i] <= '6'))
                {
                    ++count;
                }
            }
        }

        return count;
    }*/
};

//2 = B
//22 = BB V
//226 = BBF VF BY