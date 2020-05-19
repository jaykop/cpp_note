#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {

        int strings = int(A.size());
        int length = A[0].length();
        vector<int> res;
        for (int i = 0; i < length; i++)
        {
            bool add = false;
            for (int j = 0; j < strings; j++)
            {
                if (j > 0)
                {
                    char a = A[j - 1][i];
                    char b = A[j][i];

                    if (a > b) {
                        add = true;
                        break;
                    }
                }
            }
            if (add)
                res.emplace_back(i);

        }

        return res.size();
    }
};