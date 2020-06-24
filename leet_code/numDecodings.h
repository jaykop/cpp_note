#pragma once
#include <string>

using namespace std;

class Solution {
public:

    int count = 0;

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
    }
};

//2 = B
//22 = BB V
//226 = BBF VF BY